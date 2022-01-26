#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int NUM = 3;
int store1_NUM = 6;
int store2_NUM = 4;
int store3_NUM = 1;

class Student
{
private:
    int number;
    string name;
    string Id;
    double *store1;
    double *store2;
    double *store3;
    double sum;

public:
    Student();
    ~Student();
    friend ostream &operator<<(ostream &ot, const Student &st);
    friend istream &operator>>(istream &in, Student &st);
    friend ifstream &operator>>(ifstream &in, Student &st);
    friend ofstream &operator>>(ofstream &in, Student &st);
};

Student::Student()
{
    number = 0;
    name = "zyd";
    Id = "123456789";
    store1 = new double[30];
    store2 = new double[30];
    store3 = new double[30];
    sum = 0.0;
}

Student::~Student()
{
    delete[] store1;
    delete[] store2;
    delete[] store3;
}

ostream &operator<<(ostream &ot, const Student &st)
{
    ot << st.number << " " << st.name << " " << st.Id << " ";
    for (int i = 0; i < store1_NUM; i++)
    {
        i == 0 ? ot << st.store1[i] : ot << " " << st.store1[i];
    }
    ot << " ";
    for (int i = 0; i < store2_NUM; i++)
    {
        i == 0 ? ot << st.store2[i] : ot << " " << st.store1[i];
    }
    ot << " ";
    for (int i = 0; i < store3_NUM; i++)
    {
        i == 0 ? ot << st.store3[i] : ot << " " << st.store1[i];
    }
    ot << " " << st.sum << endl;
    return ot;
}

istream &operator>>(istream &in, Student &st)
{
    in >> st.number >> st.name >> st.Id;
    for (int i = 0; i < store1_NUM; i++)
    {
        in >> st.store1[i];
    }
    for (int i = 0; i < store2_NUM; i++)
    {
        in >> st.store2[i];
    }
    for (int i = 0; i < store3_NUM; i++)
    {
        in >> st.store3[i];
    }
    in >> st.sum;
    return in;
}

ifstream &operator>>(ifstream &in, Student &st)
{
    in >> st.number >> st.name >> st.Id;
    for (int i = 0; i < store1_NUM; i++)
    {
        in >> st.store1[i];
    }
    for (int i = 0; i < store2_NUM; i++)
    {
        in >> st.store2[i];
    }
    for (int i = 0; i < store3_NUM; i++)
    {
        in >> st.store3[i];
    }
    in >> st.sum;
    return in;
}

ofstream &operator>>(ofstream &ot, Student &st)
{
    ot << st.number << " " << st.name << " " << st.Id << " ";
    for (int i = 0; i < store1_NUM; i++)
    {
        i == 0 ? ot << st.store1[i] : ot << " " << st.store1[i];
    }
    ot << " ";
    for (int i = 0; i < store2_NUM; i++)
    {
        i == 0 ? ot << st.store2[i] : ot << " " << st.store1[i];
    }
    ot << " ";
    for (int i = 0; i < store3_NUM; i++)
    {
        i == 0 ? ot << st.store3[i] : ot << " " << st.store1[i];
    }
    ot << " " << st.sum << endl;
    return ot;
}

int main()
{
    ifstream infile;
    ofstream outfile;
    infile.open("../xshell/student.dat", ios::in);
    if (!infile)
    {
        cout << "未能成功打开文件" << endl;
        return 0;
    }
    Student s[3];
    for (int i = 0; i < NUM; i++)
    {
        infile >> s[i];
    }
    for (int i = 0; i < NUM; i++)
    {
        cout << s[i];
    }
    outfile.open("newst.txt",ios::out);
    for (int i = 0; i < NUM; i++)
    {
        outfile << s[i];
    }
    infile.close();
    outfile.close();
    return 0;
}