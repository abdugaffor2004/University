#include <iostream>
using namespace std;

class fig {
protected:
    float x0, y0;
    float a;
public:
    fig(float x1 = 0, float y1 = 0, float a1 = 0): x0(x1), y0(y1), a(a1) {}
    virtual float sqr() const = 0;
    virtual fig* copyf() const = 0;
    virtual ostream& show(ostream& os) {
        return os << "x0 = " << x0 << ", y0 = " << y0;
    }
    friend ostream& operator<<(ostream& os, fig& tmp) { return tmp.show(os); }
};


class tre: public fig {
    float h;
public:
    tre(float x1, float y1, float a1, float h1):
        fig(x1, y1, a1), h(h1) {}
    fig* copyf() const { return new tre(x0, y0, a, h); }
    float sqr() const { return a * h / 2; }
    ostream& show(ostream& os) {
        fig::show(os);
        return os << ", osnovanie = " << a << ", vysota = " << h << endl;
    }
};


class kv: public fig {
public:
    kv(float x1, float y1, float a1):
        fig(x1, y1, a1) {}
    fig* copyf() const
    {
        return new kv(x0, y0, a);
    }
    float sqr() const { return a * a; }
    ostream& show(ostream& os) {
        fig::show(os);
        return os << ", storona = " << a << endl;
    }
};


struct el {
    fig* pf;
    el* next;
    el(): pf(0), next(0) {}
    el(fig* f): pf(f), next(0) {}
    ~el() { delete pf->copyf(); }

    
    class flist {
        el* elf;
    public:
        flist(): elf(0) {}
        flist(const flist& fl):elf(0) {
            for (el* e = fl.elf; e; e = e->next) ins_end(*(e->pf->copyf()));
        }
        ~flist() {
            for (el* e = elf; e;) {
                el* t = e->next;
                delete e;
                e = t;
            }
        }
    

        int get_size() {
            int i = 0;
            for (el* e = elf; e; e = e->next, i++);
            return i;
        }
        el* pop_beg() {
            if (!elf) {
                cerr << "List is empty!" << endl; return 0;
            }
            el* t = elf;
            elf = t->next;
            return t;
        }
        el* pop_end() {
            if (!elf) {
                cerr << "List is empty!"; return 0;
            }
            el* p = 0;
            for (el* e = elf; e->next; e = e->next) p = e;
            if (!p) elf = 0;
            else p->next = 0;
            return p;
        }
        int ins_beg(fig& f) {
            el* t = new el(f.copyf());
            if (!t) {
                cerr << "Error memory allocation!" << endl;
                return 0;
            }
            t->next = elf;
            elf = t; return 1;
        }
        int ins_end(fig& f) {
            el* t = new el(f.copyf());
            if (!t) {
                cerr << "Error memory allocation!" << endl;
                return 0;
            }
            if (!elf) {elf = t;}
            else {
                for (el* e = elf; e->next; e = e->next);
                elf->next = t;
            }
            return 1;
        }
    
       friend ostream& operator<<(ostream& os, flist& fs) {
            for (el* e = fs.elf; e; e = e->next) {
                os << *(e->pf) << endl;
            }
            return os;
        }

        

    };
};



    int main() {
        el::flist list;
        kv* kv1 = new kv(1, 2, 3);
        kv* kv2 = new kv(4, 5, 6);
        tre* tre1 = new tre(7, 8, 9, 10);
        tre* tre2 = new tre(11, 12, 13, 14);
        list.ins_end(*kv1);
        list.ins_end(*kv2);
        list.ins_end(*tre1);
        list.ins_end(*tre2);

        cout << list << endl;
        
    }


   
