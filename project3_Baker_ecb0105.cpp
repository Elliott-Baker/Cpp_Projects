/*
    Name: Elliott Baker
    ID: ecb0105
    File: project3_Baker_ecb0105.cpp
    Compile using g++ -std=c++11 on Auburn server
    Sources: I used the hints given by Dr. Li and the C++ documentation website.
*/
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Checks to see if the file opens properly
bool checkFile(string);

// Returns the integers in the given file in a vector
vector<int> readFile(string);

// Returns the sorted merge of two vectors (returns a vector)
vector<int> merge(vector<int>, vector<int>);

// Writes sorted vector to a new file named by the user
void writeFile(string, vector<int>);

// Prompts user for first and second file name.
// Continues if file not found.
// Prints the result of the merged vectors.
int main()
{
    string inputFile1;
    string inputFile2;
    string outputFile;
    vector<int> numbers1;
    vector<int> numbers2;
    vector<int> sortedNumbers;
    int outputSize;

    do
    {
        cout << "***Welcome to Elliott's sorting program***\n";
        cout << "Enter the first input file name: ";
        cin >> inputFile1;
    } while (cin.fail() || !checkFile(inputFile1));
    numbers1 = readFile(inputFile1);

    cout << "The list of " << numbers1.size() << " numbers in file " << inputFile1 << " is:\n";

    for (int a = 0; a < numbers1.size(); a++)
    {
        cout << numbers1.at(a) << "\n";
    }
    cout << "\n";

    do
    {
        cout << "Enter the second input file name: ";
        cin >> inputFile2;
    } while (cin.fail() || !checkFile(inputFile2));
    numbers2 = readFile(inputFile2);

    cout << "The list of " << numbers2.size() << " numbers in file " << inputFile2 << " is:\n";

    for (int a = 0; a < numbers2.size(); a++)
    {
        cout << numbers2.at(a) << "\n";
    }
    cout << "\n";

    outputSize = numbers1.size() + numbers2.size();
    do
    {
        cout << "The sorted list of " << outputSize << " numbers is: ";
        sortedNumbers = merge(numbers1, numbers2);
        for (int a = 0; a < sortedNumbers.size(); a++)
        {
            cout << sortedNumbers.at(a) << "\n";
        }
        cout << "\nEnter the output file name: ";
        cin >> outputFile;
        writeFile(outputFile, sortedNumbers);
    } while (cin.fail());
    cout << "***Please check the new file-" << outputFile << "***\n";
    cout << "***Goodbye.***\n";
    return 0;
}

bool checkFile(string file)
{
    ifstream inStream;

    inStream.open(file.c_str());
    if (inStream.fail())
    {
        return false;
    }

    inStream.close();
    return true;
}

vector<int> readFile(string file)
{
    vector<int> v;
    ifstream inStream;
    int data;

    inStream.open(file);

    inStream >> data;
    while (!inStream.eof())
    {
        v.push_back(data);
        inStream >> data;
    }

    inStream.close();
    return v;
}

vector<int> merge(vector<int> v1, vector<int> v2)
{
    vector<int> result;
    int v1Index = 0;
    int v2Index = 0;
    while (v1Index < v1.size() && v2Index < v2.size())
    {
        if (v1.at(v1Index) > v2.at(v2Index))
        {
            result.push_back(v2.at(v2Index));
            v2Index++;
        }
        else
        {
            result.push_back(v1.at(v1Index));
            v1Index++;
        }
    }

    while (v2Index < v2.size())
    {
        result.push_back(v2.at(v2Index));
        v2Index++;
    }

    while (v1Index < v1.size())
    {
        result.push_back(v1.at(v1Index));
        v1Index++;
    }

    return result;
}

void writeFile(string file, vector<int> v)
{
    ofstream outFile;
    outFile.open(file, ios::out);

    for (int a = 0; a < v.size(); a++)
    {
        outFile << v.at(a) << "\n";
    }
    outFile.close();
}