

#include <iostream>
#include <vector>

using namespace std;


//task1
int getValue()
{
    while(true)
    {
        cout << "Enter int value: ";
        int a = 0;
        cin >> a;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else
            return a;
    }
    return 0;
}

//task2
void endll()
{
    cout << '\n' << '\n';
    cin.clear();
}

//task3
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
        cout << "card constructor" << endl;
    }

    ~Card() { cout << "card destructor" << endl; }

    friend ostream& operator << (ostream& os, const Card& aCard);

    int getValue() const;
    void flip() { m_isFaceUp = !(m_isFaceUp); }

    

private:
    rank m_rank;
    suit m_suit;
    bool m_isFaceUp;
};

//task5
ostream& operator<< (ostream& out, const Card& card)
{
    if (card.m_isFaceUp == false) {
        cout << "XX\n";
    }
    else {
        cout << "Rank: " << card.m_rank << "\n";
        cout << "Suit: " << card.m_suit << "\n";
    }
}

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
    Hand() { m_cards.reserve(7); }
    ~Hand() { clear(); }

    void add(Card* pcard);

    void clear();
    int getTotal() const;

protected:
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
    GenereticPlayer(string name) : m_name(name) {}
    ~GenereticPlayer() {}
    friend ostream& operator << (ostream& os, const GenereticPlayer& agen);

    virtual void IsHitting() = 0;
    bool IsBoosted();
    void Bust();
    string GetName() const;
};

//task5
ostream& operator << (ostream& os, const GenereticPlayer& agen)
{
    cout << "Name: " << agen.m_name << "\n";
    cout << "Cards: ";
    vector<Card*>::const_iterator iter;
    for (iter = agen.m_cards.begin(); iter != agen.m_cards.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << '\n';
    cout << "Total: " << agen.getTotal() << "\n";
}

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

string GenereticPlayer::GetName() const
{
    return m_name;
}

//__________________________________________начинается здесь!

class Player : public GenereticPlayer
{
public:
    Player(const string& name = "") {}
    virtual ~Player() {}
    virtual bool IsHitting() const =0;
    void Win() const;
    void Lose() const;
    void Push() const;
};

void Player::Win() const
{
    cout << GetName() << "Win!\n";
}

void Player::Lose() const
{
    cout << GetName() << "Lose!\n";
}

void Player::Push() const
{
    cout << GetName() << "Push!\n";
}


//task4

class House : public GenereticPlayer
{
public:
    House(const string& name = "House") {}
    virtual ~House() {}
    virtual bool IsHitting() const;
    void FlipFirstCard();
};

bool House::IsHitting() const
{
    return (getTotal() <= 16);
}

void House::FlipFirstCard()
{
    if (!(m_cards.empty()))
    {
        m_cards[0]->flip();
    }
    else
    {
        cout << "No card to flip!\n";
    }
}



int main()
{
    //task1
    {
        int a = getValue();
        cout << a;
    }

    //task2
    {
        endll();
    }
}

