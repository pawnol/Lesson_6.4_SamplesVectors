/*
Lesson 6.4 Samples Vectors
Pawelski
5/4/2021
Here are the samples for vectors. Please note that you need
the line #include <vector> in order to use vectors!
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
Prints all the numbers in the vector on their own
line. Notice that we do not need to pass the length
of the vector as C++ can find the length using size().
*/
void print(vector<int> args)
{
    for (int i = 0; i < args.size(); i++)
    {
        cout << args[i] << "\n";
    }
}

/*
Displays each element in the vector to the console.
*/
void print(vector<string> args)
{
    for (int i = 0; i < args.size(); i++)
    {
        cout << args[i] << "\n";
    }
}

/*
Returns the index of t in v. If t is not in v,
returns -1.
*/
int find(vector<string> v, string t)
{
    for (int i = 0; i < v.size(); i++) 
    {
        if (v[i] == t)
        {
            return i;
        }
    }
    return -1;
}

/*
Splits the string into seperate words and returns
a vector containing the words. This function will also
include any punctuation at the end of the sentence as 
a part of the last word. This could be remedied with
an additional if statement at the end to check the last
character of the word and remove as necessary, but this
has not been implement for brevity.
*/
vector<string> splitWords(string text)
{
    // notice the order of the declarations!
    int currentSpace = -1;
    string word;
    int nextSpace = text.find(" ");
    vector<string> allWords;

    // check if the text only contains 1 word
    if (nextSpace == string::npos)
    {
        allWords.push_back(text);
        return allWords;
    }

    // text has multiple words
    while (nextSpace != string::npos)
    {
        word = text.substr(currentSpace + 1, nextSpace - currentSpace);
        allWords.push_back(word);
        currentSpace = nextSpace;
        nextSpace = text.find(" ", nextSpace + 1);
    }
    // adds the last word
    word = text.substr(currentSpace + 1);
    allWords.push_back(word);
    return allWords;
}

int main()
{
    /*
    Example #1
    Declaring and initializing a vector.
    */
    vector<int> numbers1;
    vector<int> numbers2 = { 1, 2, 4, 5 };
    
    /*
    Example #2
    Accessing an element in a vector. Currently,
    there are no elements in numbers1. If you try
    to access an element, C++ will throw an error!
    */
    cout << numbers2[0] << "\n";
    cout << numbers2[2] << "\n\n";
    int sum = numbers2[0] + numbers2[1] + numbers2[2] + numbers2[3];
    cout << "Sum of numbers1 using bad method = " << sum << "\n\n";

    /*
    Example #3
    Traversing a vector. Notice how we can find the length of
    the vector using the size() function.
    */
    sum = 0;
    for (int i = 0; i < numbers2.size(); i++)
    {
        sum += numbers2[i];
    }
    cout << "Sum of numbers1 using good method = " << sum << "\n\n";

    /*
    Example #4
    This example demonstrates how to call a function on a vector.
    In this case, we call the at() function, which returns the
    element at the given position. This example also demonstrates
    how to find the average values stored in a vector.
    */
    double dataSetSum = 0;
    vector<double> dataSet = { 5.6, 2.1, 6.3, 5, 9, 22 };
    for (int i = 0; i < dataSet.size(); i++)
    {
        dataSetSum += dataSet.at(i);
    }
    cout << "The average is " << dataSetSum / dataSet.size() << ".\n\n";

    /*
    Example #5
    Adding elements to a vector. In this case, push_back()
    add an element to the end of the vector while insert() adds
    the element at the given position.
    */
    vector<string> namesVector;
    namesVector.push_back("Jim");
    namesVector.push_back("Joe");
    namesVector.push_back("Bob");
    namesVector.push_back("Eve");
    namesVector.push_back("Mia");
    namesVector.push_back("Ivy");
    print(namesVector);
    cout << "\n";
    namesVector.insert(namesVector.begin(), "Jay");
    print(namesVector);
    cout << "\n";
    namesVector.insert(namesVector.begin() + 2, "Ada");
    print(namesVector);
    cout << "\n";

    /*
    Example #6
    Deleting elements from a vector. In this case, pop_back()
    removes the last element while erase() removes the element
    at the given position.
    */
    namesVector.pop_back();
    print(namesVector);
    cout << "\n";
    namesVector.erase(namesVector.begin() + 1);
    print(namesVector);
    cout << "\n";
    
    /*
    Example #7
    In this example, I show how to search a vector for a
    value and then remove it. More on passing vectors as
    a parameter in the next example!
    */
    int index;
    string name;
    cout << "What name do you want to remove from the list? >> ";
    cin >> name;
    index = find(namesVector, name);
    if (index == -1)
    {
        cout << "That name is not on the list!\n";
    }
    else
    {
        namesVector.erase(namesVector.begin() + index);
        cout << "Found and removed name. "
            << "Here is the updated list...\n";
        print(namesVector);
    }
    cout << "\n";

    /*
    Example #8
    Passing a vector to a function. This example shows how
    to pass a vertor to a function. Notice how you do not
    need to specify the size of the vector as a parameter.
    */
    vector<int> myVector;
    vector<int> anotherVector = { 6, 2, 3 , 4 };
    print(anotherVector);
    cout << "\n";

    /*
    Example #9
    Return a vector from a function. In this example, the
    function splits the text entered by the user into seperate
    words.
    */
    string userInput;
    cout << "Enter a phrase or sentence >> ";
    getline(cin, userInput);
    print(splitWords(userInput));
    return 0;
}

