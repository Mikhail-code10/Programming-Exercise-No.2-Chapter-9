#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Set Konstanta untuk Jumlah Murid
const int NUM_STUDENTS = 20;

// Definisi Struktur
struct studentType {
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

// Prototype Fungsi
void getData(studentType students[], int size);
void assignGrade(studentType students[], int size);
int findHighestScore(studentType students[], int size);
void printHighest(const studentType students[], int size, int highestScore);
void printAll(const studentType students[], int size);

int main() {
    studentType students[NUM_STUDENTS];

    // Manggil Fungsi
    getData(students, NUM_STUDENTS);
    assignGrade(students, NUM_STUDENTS);
    int highestScore = findHighestScore(students, NUM_STUDENTS);
    printAll(students, NUM_STUDENTS);
    printHighest(students, NUM_STUDENTS, highestScore);

    return 0;
}

// a. Fungsi Baca Data Murid
void getData(studentType students[], int size) {
    cout << "Enter first name, last name, and test score for " 
         << size << " students:\n";
    for (int i = 0; i < size; i++) {
        cin >> students[i].studentFName >> students[i].studentLName >> students[i].testScore;
    }
}

// b. Fungsi Beri Nilai Huruf
void assignGrade(studentType students[], int size) {
    for (int i = 0; i < size; i++) {
        int score = students[i].testScore;
        if (score >= 90)
            students[i].grade = 'A';
        else if (score >= 80)
            students[i].grade = 'B';
        else if (score >= 70)
            students[i].grade = 'C';
        else if (score >= 60)
            students[i].grade = 'D';
        else
            students[i].grade = 'F';
    }
}

// c. Fungsi Mencari Nilai Tertinggi
int findHighestScore(studentType students[], int size) {
    int highest = students[0].testScore;
    for (int i = 1; i < size; i++) {
        if (students[i].testScore > highest)
            highest = students[i].testScore;
    }
    return highest;
}

// d. Fungsi Tampilkan Murid dengan Nilai Tertinggi
void printHighest(const studentType students[], int size, int highestScore) {
    cout << "\nHighest Test Score: " << highestScore << endl;
    cout << "Students with the highest score:\n";
    for (int i = 0; i < size; i++) {
        if (students[i].testScore == highestScore) {
            cout << left << setw(15) << students[i].studentLName + ", " + students[i].studentFName << endl;
        }
    }
}

// Fungsi Tampilkan Data Murid
void printAll(const studentType students[], int size) {
    cout << "\nStudents' Grades:\n";
    cout << left << setw(20) << "Name" 
         << setw(12) << "Score" 
         << "Grade" << endl;
    cout << "--------------------------------\n";

    for (int i = 0; i < size; i++) {
        cout << left << setw(20)
             << (students[i].studentLName + ", " + students[i].studentFName)
             << setw(12) << students[i].testScore
             << students[i].grade << endl;
    }
}

