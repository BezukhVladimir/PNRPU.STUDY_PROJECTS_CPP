#include <vector>
#include <iostream>

using namespace std;

enum 
{ 
    R = 1,
    L = -1,
    H = 0 
};

struct State 
{ 
    string q;
    char sym;
};

struct Rule 
{
    string text; // содержимоеправила
    string curQ; // текущее состояние
    string nextQ; // следующее состояние
    char curSym; // текущий символ
    char nextSym; // следующий символ
    char cmd; // команда на перемещение
};

class MT 
{
public:
    MT(string, string, int); // конструктор
    
    char getSym()const 
    { // селектор символа из тек. позиции
        return mem[curPos];
    }
    
    string getState()const 
    { // селектор текущего состояния
        return curState.q; 
    }
    
    string getMem() const 
    { // селектор содержимого ленты
        return mem;
    }
    
    bool addRule(string); // добавление правила
    void step(); // шаг машины

private:
    void process(int);
    string mem; // содержимое ленты
    int width; // ширина поля записи состояния
    int curPos; // текущая позиция на ленте
    State curState; // текущее состояние машины
    vector<Rule> rules; // вектор правил (программа)
    int rNum; // количество правил
};

MT::MT(string mem, string beg_state, int width)
{
    this->mem = mem;
    this->width = width;
    curPos = 0;
    curState.q = beg_state;
    curState.sym = mem[curPos];
    rNum = 0;
}

bool MT::addRule(string rule)
{
    rules.push_back(*new Rule);
    rules[rNum].text = rule;
    rules[rNum].curQ.assign(rule, 0, width);
    rules[rNum].curSym = rule[width];
    size_t pos = rule.find("->") + (width - 1);
    rules[rNum].nextQ.assign(rule, pos, width);
    rules[rNum].cmd = rule[rule.length() - 1];
    rules[rNum++].nextSym = rule[rule.length() - 2];
    return true;
}

void MT::process(int i) 
{
    if (rules[i].cmd == 'L')
        curPos += L; 
    else if (rules[i].cmd == 'R')
        curPos += R;
    curState.q = rules[i].nextQ;
    
    if (curPos < 0)
        return; 
    
    if (curPos >= mem.length())
        mem.resize(mem.size() + 1, '^');
    curState.sym = mem[curPos];
}

void MT::step() 
{ 
    int i; 
    
    for (i = 0; i < rNum; i++)
    {
        if (curState.q == rules[i].curQ && curState.sym == rules[i].curSym) 
        {
            if (rules[i].nextSym != ' ')
                mem[curPos] = rules[i].nextSym;
            
            process(i);
        }
    }
}

int main()
{
    MT mt("*11x11=*", "q00", 3);

    cout << mt.getMem() << ""
        << mt.getState() << " "
        << mt.getSym() << endl;

    mt.addRule("q00*->q00 R");
    mt.addRule("q001->q00 R");
    mt.addRule("q00x->q01xR");
    mt.addRule("q011->q02aR");
    mt.addRule("q021->q021L");
    mt.addRule("q02a->q02aL");
    mt.addRule("q02=->q02=L");
    mt.addRule("q02x->q03xL");
    mt.addRule("q031->q04aR");
    mt.addRule("q03a->q03aL");
    mt.addRule("q03*->q06*R");
    mt.addRule("q04x->q04xR");
    mt.addRule("q04a->q04aR");
    mt.addRule("q04=->q04=R");
    mt.addRule("q041->q041R");
    mt.addRule("q04*->q051R");
    mt.addRule("q05^->q02*L");
    mt.addRule("q06a->q061R");
    mt.addRule("q06x->q07xR");
    mt.addRule("q07a->q07aR");
    mt.addRule("q071->q02aR");
    mt.addRule("q07=->q08=L");
    mt.addRule("q08a->q081L");
    mt.addRule("q08x->q09 H");

    for (;;)
    {
        mt.step();
        cout << mt.getMem()
            << "" << mt.getState()
            << "" << mt.getSym() << endl;

        if (mt.getState() == "q09")
            break;
    }
}