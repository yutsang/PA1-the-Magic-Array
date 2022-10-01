/*
 * COMP2011 (Fall 2021) Programming Assignment 1
 *
 * Student name: TSANG YU
 * Student ID: 20705565
 * Student email: ytsang@ust.hk
 *
 */

#include <iostream>
#include <limits>
using namespace std;

// Global Constants
// You cannot modify these global constants
// You cannot use your own global variables
const int MAX_ARR_LEN = 16;
const int MAX_ROTATIONS = 1024;
// End of Global Constants

// Helper Functions
// Declare additional helper functions below when necessary
// int myHelperFunction(int argc, char *argv[])

// End of Helper Functions

// Tasks
// Please write your code under the TODO tag
// You cannot change the function declarations

// Task 1
int rotate(int arr[], int arrLen, int k)
{
    // Task 1 TODO
    if ((k < 0) || (k >= arrLen)){
        cout << "Error: Index k is out of range." << "\n";
        return -1;
    }
    else {
        int temp[MAX_ARR_LEN];
        for (int i = 0; i < k+1; i++){
            temp[i]=arr[k-i];
        }
        for (int i = 0; i < k+1; i++){
            arr[i] = temp[i];
        } 
        return 0;
    }
    // End of Task 1 TODO
}

//Task 2
int swapAndRecord(int arr[], int arrLen, int indexA, int indexB, int rotations[], int &rotationLen)
{
    // Task 2 TODO
    //tester
    bool proceed = true;
    if (rotationLen > MAX_ROTATIONS){rotationLen = 0;}
    if (indexA == indexB){proceed = false;};
    if (indexA < 0 || indexA >= arrLen){proceed = false;};
    if (indexB < 0 || indexB >= arrLen){proceed = false;};
    if (!proceed){cout << "Error: Index out of range." << endl; return -1;}
    else {
    //initialisation
    int itemp = 0;
    if (indexA > indexB){itemp = indexA; indexA = indexB; indexB = itemp;}
    int temrotation[6] = {indexA-1, indexA, indexB, indexB-indexA-1, indexB-indexA-2, indexB-1};
    //search for duplication
    /*
    int dupCheck[MAX_ARR_LEN];
    for (int i = 0; i < 6; i++)
        for (int j = i+1; j < 6; j++){
            if temrotation[]
        }
    //search end
    */
    for (int i = 0; i < 6; i++){
        if (temrotation[i] > 0){
            rotate(arr, arrLen, temrotation[i]);
            rotations[rotationLen] = temrotation[i];
            rotationLen++;
        }
    }
    return 0;
    }
    // End of Task 2 TODO
}

//Task 3
void sortAndRecord(int arr[], int arrLen, int rotations[], int &rotationLen)
{
    // Task 3 TODO
    for (int i = 0; i < arrLen-1; i++)
        for (int j = i+1; j < arrLen; j++){
            if (arr[i] > arr[j]){ 
                swapAndRecord(arr, arrLen, i, j, rotations, rotationLen);
            }
        }
    // End of Task 3 TODO
}

//Task 4
int transformAndRecord(int src[], int tgt[], int arrLen, int rotations[], int &rotationLen)
{
    // Task 4 TODO
    rotationLen = 0;
    int compare_array[MAX_ARR_LEN];
    int src1[arrLen], tgt1[arrLen];
    //check correctness
    int tem = 0; 
    bool tester = true;

    for (int i = 0; i < arrLen; i++){src1[i] = src[i]; tgt1[i] = tgt[i];}

    for (int i = 0; i < arrLen-1; i++)
        for (int j = i+1; j < arrLen; j++){
            if (tgt1[i] > tgt1[j]){ 
                tem = tgt1[i]; tgt1[i] = tgt1[j]; tgt1[j] = tem;
            }
            if (src1[i] > src1[j]){ 
                tem = src1[i]; src1[i] = src1[j]; src1[j] = tem;
            }
        }
    
    for (int i = 0; i < arrLen; i++){
        if (!(src1[i] == tgt1[i])){tester = false;}
    }

    if (tester){
        for (int i = 0; i < MAX_ARR_LEN; i++){
            if (i >= arrLen){compare_array[i] = 0;}
                else {
                    //Same = 0; Different = 1;
                    if (src[i] == tgt[i]){compare_array[i] = 0;}
                        else {compare_array[i] = 1;}
                }
        }
        /////////////////
 
        for (int i = 0; i < arrLen-1; i++){
            if (compare_array[i] != 0){
                for (int j = i+1; j < arrLen; j++){
                    if ((tgt[i] == src[j])&&(compare_array[i]!=0)&&(compare_array[j]!=0)) {
                        swapAndRecord(src, arrLen, i, j, rotations, rotationLen);
                        compare_array[i] = 0;
                        //tem = src[i]; src[i] = src[j]; src[j] = tem;
                        if (src[j] == tgt[j]){compare_array[j] = 0;}
                        break;
                    }
                }
            }
        }

        /////////////////
        return 0;
    }
        else {
            return -1;
        }


    // End of Task 4 TODO
}

// DO NOT WRITE ANYTHING AFTER THIS LINE. ANYTHING AFTER THIS LINE WILL BE REPLACED

int init(int arr[], int arrLen)
{
    char buffer;
    cout << "? Please enter one digit at a time and press return:" << endl;
    for (int i = 0; i < arrLen; i++)
    {
        cin >> buffer;
        if (buffer > '9' || buffer < '0')
        {
            cout << "Error: Illegal digit input." << endl;
            return -1;
        }
        else
        {
            arr[i] = (int)buffer - 48;
        }
    }
    return 0;
}

void printArr(int arr[], int arrLen)
{
    for (int i = 0; i < arrLen; i++)
    {
        cout << arr[i];
        if (i < arrLen - 1)
        {
            cout << ',';
        }
    }
    cout << endl;
}

void runInit(int arr[], int &arrLen)
{
    cout << "##################################################" << endl;
    cout << "# Initializing" << endl;
    cout << endl;

    int initResult = -1;
    while (initResult < 0)
    {
        cout << "? Enter the length of your array:" << endl;
        cin >> arrLen;
        if (arrLen < 1)
        {
            cout << "! Error: Length should be larger than 0." << endl;
            continue;
        }
        else if (arrLen > MAX_ARR_LEN)
        {
            cout << "Error: arrLen of should be less than or equal to " << MAX_ARR_LEN << endl;
            continue;
        }
        cout << "? Enter " << arrLen << " elements of your array." << endl;
        initResult = init(arr, arrLen);
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    cout << "! Initialization succeeded!" << endl;
    cout << "! Printing the array:" << endl;
    cout << endl;
    printArr(arr, arrLen);
    cout << endl;
}

void runPrint(int arr[], int arrLen)
{
    cout << "##################################################" << endl;
    cout << "# Printing the array" << endl;
    cout << endl;
    printArr(arr, arrLen);
    cout << endl;
}

void runRotate(int arr[], int arrLen)
{
    int k, output;
    cout << "##################################################" << endl;
    cout << "# Rotating the array:" << endl;
    cout << "? Enter the index k:";
    cin >> k;
    output = rotate(arr, arrLen, k);
    if (output < 0)
    {
        cout << "! Error: Rotation failed." << endl;
    }
    else
    {
        cout << "! Rotated." << endl;
        cout << "! Array after rotation:" << endl;
        cout << endl;
        printArr(arr, arrLen);
        cout << endl;
    }
}

void runSwap(int arr[], int arrLen)
{
    int indexA, indexB, rotations[MAX_ROTATIONS], rotationLen, output;
    cout << "##################################################" << endl;
    cout << "# Swapping elements:" << endl;
    cout << "? Enter the 1st index:";
    cin >> indexA;
    cout << "? Enter the 2nd index:";
    cin >> indexB;
    output = swapAndRecord(arr, arrLen, indexA, indexB, rotations, rotationLen);
    if (output < 0)
    {
        cout << "! Error: Swap failed." << endl;
    }
    else
    {
        cout << "! Swapped." << endl;
        cout << "! Array after swap:" << endl;
        cout << endl;
        printArr(arr, arrLen);
        cout << endl;
        cout << "! Rotations:" << endl;
        cout << endl;
        printArr(rotations, rotationLen);
        cout << endl;
    }
}

void runSort(int arr[], int arrLen)
{
    int from, to, rotations[MAX_ROTATIONS], rotationLen, output;
    cout << "##################################################" << endl;
    cout << "# Sorting the array:" << endl;
    sortAndRecord(arr, arrLen, rotations, rotationLen);
    cout << "! Sorted." << endl;
    cout << "! Array after sorting:" << endl;
    cout << endl;
    printArr(arr, arrLen);
    cout << endl;
    cout << "! Rotations:" << endl;
    cout << endl;
    printArr(rotations, rotationLen);
    cout << endl;
}

void runTransform(int arr[], int arrLen)
{
    int from, to, rotations[MAX_ROTATIONS], rotationLen, output;
    cout << "##################################################" << endl;
    cout << "# Transforming src array to the tgt:" << endl;
    int tgt[MAX_ARR_LEN], initResult = -1;
    while (initResult < 0)
    {
        cout << "? Enter " << arrLen << " elements of the tgt array." << endl;
        initResult = init(tgt, arrLen);
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    cout << "! The target array:" << endl;
    cout << endl;
    printArr(tgt, arrLen);
    cout << endl;
    output = transformAndRecord(arr, tgt, arrLen, rotations, rotationLen);
    if (output < 0)
    {
        cout << "! Error: Cannot transform array to target." << endl;
    }
    else
    {
        cout << "! Transformed." << endl;
        cout << "! Array after transformation:" << endl;
        cout << endl;
        printArr(arr, arrLen);
        cout << endl;
        cout << "! Rotations:" << endl;
        cout << endl;
        printArr(rotations, rotationLen);
        cout << endl;
    }
}

void runOption()
{
    int arrLen = 0;
    bool is_initialized = false;
    int src[MAX_ARR_LEN];
    int tgt[MAX_ARR_LEN];
    int option;
    cout << "===========================================" << endl;
    cout << "= Welcome to COMP2011 PA1 1D Rubik's Cube =" << endl;
    cout << "===========================================" << endl;

    while (true)
    {
        if (!is_initialized)
        {
            runInit(src, arrLen);
            is_initialized = true;
        }
        else
        {
            cout << "##################################################" << endl;
            cout << "# Main Menu" << endl;
            cout << endl;
            cout << "1 Initialize" << endl;
            cout << "2 Print" << endl;
            cout << "3 Rotate" << endl;
            cout << "4 Swap" << endl;
            cout << "5 Sort" << endl;
            cout << "6 Transform" << endl;
            cout << "0 Exit" << endl;
            cout << endl;
            cout << "? Please enter an option (0-6): ";
            cin >> option;
            switch (option)
            {
            case 0:
                cout << "! Bye Bye." << endl;
                return;
            case 1:
                runInit(src, arrLen);
                break;
            case 2:
                runPrint(src, arrLen);
                break;
            case 3:
                runRotate(src, arrLen);
                break;
            case 4:
                runSwap(src, arrLen);
                break;
            case 5:
                runSort(src, arrLen);
                break;
            case 6:
                runTransform(src, arrLen);
                break;
            default:
                cout << "Illegal Choice, please try again." << endl;
                break;
            }
            cout << "! Returning to main menu." << endl;
        }
    }
}

int main()
{
    runOption();
    return 0;
}
