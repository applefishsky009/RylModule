#include <typeinfo>
#include <unistd.h>
#include <E:\RylModule\list.h>
#include <E:\RylModule\tree.h>
#include <E:\RylModule\string.h>
#include <E:\RylModule\vector.h>
#include <E:\RylModule\iterator.h>
using namespace std;

int main()
{
    //vector.h
    {
        cout << "1D vector show" << endl;
        const vector<int> show1DVectorInt = {1, 2, 3, 4};
        const vector<double> show1DVectorDouble = {1.1, 2.2, 3.3, 4.4};
        show1DVector(show1DVectorInt);
        show1DVector(show1DVectorDouble);
        cout << endl;

        cout << "2D vector show" << endl;
        const vector<vector<int>> show2DVectorInt =
            {{1, 2, 3, 4},
             {5, 6, 7, 8},
             {9, 0, 1, 2},
             {3, 4, 5, 6}};
        const vector<vector<double>> show2DVectorDouble =
            {{1.1, 2.2, 3.3, 4.4},
             {5.5, 6.6, 7.7, 8.8},
             {9.9, 0.0, 1.1, 2.2},
             {3.3, 4.4, 5.5, 6.6}};
        show2DVector(show2DVectorInt);
        show2DVector(show2DVectorDouble);
        cout << endl;

        cout << "reverse vector show" << endl;
        vector<int> vectorReverseInt = {1, 2, 3, 4, 5, 6};
        reverseVectorInPlace(vectorReverseInt);
        show1DVector(vectorReverseInt);
        vector<double> vectorReverseDouble = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
        reverseVectorInPlace(vectorReverseDouble);
        show1DVector(vectorReverseDouble);
        cout << endl;
    }

    //string.h
    {
        cout << "string split to vector" << endl;
        //vector<int> string2Vector = stringTOVectorInt();
        //show1DVector(string2Vector);
        cout << endl;
    }

    //list.h
    {
        cout << "construct & show list" << endl;
        vector<int> list{1, 2, 3, 4, 5, 6};
        ListNode *head = constructList(list);
        showList(head);
        cout << endl;

        cout << "reverse list" << endl;
        ListNode *listReverse = reverseListInPlace(head);
        showList(listReverse);
        cout << endl;
    }

    //tree.h
    {
        cout << "FullBiTree show" << endl;
        vector<int> IntTree = {0, -1, 2, -1, -1, 5, 6, -1, -1, -1, -1, 11, 12};
        TreeNode *rootInt = constructTree();//(IntTree);
        showTree(rootInt);
        cout << endl;
    }

    //iterator.h
    {
        cout << "iterator function" << endl;
        const vector<int> show1DVectorInt = {1, 2, 3, 4};
        const vector<double> show1DVectorDouble = {1.1, 2.2, 3.3, 4.4};
        showByInterator(show1DVectorInt.begin(), show1DVectorInt.end());
        showByInterator(show1DVectorDouble.begin(), show1DVectorDouble.end());
    }
    //sleep(10);  //sleep是s，Sleep是ms.
    return 0;
}