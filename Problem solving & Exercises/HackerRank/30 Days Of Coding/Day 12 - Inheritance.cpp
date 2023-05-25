#include <iostream>
#include <vector>

using namespace std;

class Person
{
protected:
    string firstName;
    string lastName;
    int id;

public:
    Person(string firstName, string lastName, int identification)
    {
        this->firstName = firstName;
        this->lastName = lastName;
        this->id = identification;
    }
    void printPerson()
    {
        cout << "Name: " << lastName << ", " << firstName << "\nID: " << id << "\n";
    }
};
class Student : public Person
{
private:
    vector<int> testScores;

public:
    // Write your constructor
    Student(string firstName, string lastName, int id, vector<int> scores) : Person(firstName, lastName, id)
    {
        this->testScores = scores;
    }

    // Write char calculate()
    char calculate()
    {
        int sumScore = 0;
        for (int i = 0; i < testScores.size(); i++)
        {
            sumScore += testScores[i];
        }
        int averageScore = sumScore / testScores.size();

        if (averageScore <= 100 && averageScore >= 90)
        {
            return 'O';
        }
        else if (averageScore < 90 && averageScore >= 80)
        {
            return 'E';
        }
        else if (averageScore < 80 && averageScore >= 70)
        {
            return 'A';
        }
        else if (averageScore < 70 && averageScore >= 55)
        {
            return 'P';
        }
        else if (averageScore < 55 && averageScore >= 40)
        {
            return 'D';
        }
        return 'T';
    }
};
int main()
{
    string firstName;
    string lastName;
    int id;
    int numScores;
    cin >> firstName >> lastName >> id >> numScores;
    vector<int> scores;
    for (int i = 0; i < numScores; i++)
    {
        int tmpScore;
        cin >> tmpScore;
        scores.push_back(tmpScore);
    }
    Student *s = new Student(firstName, lastName, id, scores);
    s->printPerson();
    cout << "Grade: " << s->calculate() << "\n";
    return 0;
}