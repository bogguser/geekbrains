
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;


//task1
template <class T>
class Pair1
{
private:
    T m_first;
    T m_second;
public:
    Pair1(T a, T b) : m_first(a), m_second(b) {}

    T first() const { return m_first; };
    T second() const { return m_second;};

};

//task2
template <class T, class S>
class Pair
{
private:
    T m_first;
    S m_second;
public:
    Pair() {}
    Pair(T a, S b) : m_first(a), m_second(b) {}

    T first() const { return m_first; };
    S second() const { return m_second; };

};

//task3
template <class S>
class StringValuePair :  public Pair <string , S>
{
public:    
        StringValuePair() {}
        StringValuePair(string a, S b) : Pair<string, S>(a,b) {}
};

//task4

class Card
    {
    public:
        enum rank {
            ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
            JACK, QUEEN, KING
        };
        enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };
    
        Card(rank r = ACE, suit s = SPADES, bool ifu = true)
            : m_rank(r), m_suit(s), m_isFaceUp(ifu) {
              cout << "card constructor"<<endl;
        }
    
        ~Card() { cout << "card destructor"<<endl; } 
    
        int getValue() const;
        void flip() { m_isFaceUp = !(m_isFaceUp); }
    
    private:
        rank m_rank;
        suit m_suit;
        bool m_isFaceUp;
    };
    
    
    int Card::getValue() const
    {
        int value = 0;
        if (m_isFaceUp)
        {
            value = m_rank;
            if (value > 10)
            {
                value = 10;
            }
        }
        return value;
    }

class Hand
    {
    public:
        Hand(){ m_cards.reserve(7); }
        ~Hand() { clear(); }
    
        void add(Card* pcard);
    
        void clear();
        int getTotal() const;
    
    private:
        vector<Card*> m_cards;
    };
    
    
    
    void Hand::add(Card* pcard)
    {
        m_cards.push_back(pcard);
    }
    
    void Hand::clear()
    {
        
        vector<Card*>::iterator iter = m_cards.begin();
        for (iter = m_cards.begin(); iter != m_cards.end(); ++iter)
        {
            delete* iter;
            *iter = 0;
        }
        m_cards.clear();
    }
    
    
    int Hand::getTotal() const
    {
        
        if (m_cards.empty())
            return 0;
    
        
        if (m_cards[0]->getValue() == 0)
            return 0;
    
        
        int total = 0;
        vector<Card*>::const_iterator iter;
        for (iter = m_cards.begin(); iter != m_cards.end(); ++iter)
        {
            total += (*iter)->getValue();
        }
    
        
        bool containsAce = false;
        for (iter = m_cards.begin(); iter != m_cards.end(); ++iter)
        {
            if ((*iter)->getValue() == Card::ACE)
            {
               containsAce = true;
            }
        }
    
        
        if (containsAce && total <= 11)
        {
            total += 10;
       }
    
       return total;
    }

    class GenereticPlayer : public Hand
    {
    private:
        string m_name = "Unknow";
    public:
        GenereticPlayer() = default;
        GenereticPlayer(string name): m_name(name) {}
        ~GenereticPlayer (){}

        virtual void IsHitting() =0;
        bool IsBoosted();
        void Bust();
    };

    bool GenereticPlayer::IsBoosted()
    {
        int boost = getTotal();
        if (boost > 21)
        {
            return true;
        }
        else { return false; }
    }

    void GenereticPlayer::Bust()
    {
        cout << m_name << " brute force\n";
    }

int main()
{
    //task1
    {
        Pair1 <int> p1(6, 9);
        cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

        const Pair1 <double> p2(3.4, 7.8);
        cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
    }
    //task2
    {
        Pair<int, double> p1(6, 7.8);
        cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

        const Pair<double, int> p2(3.4, 5);
        cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
    }
    //task3
    {
        StringValuePair <int> svp("Amazing", 7);
        std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
    }
}
