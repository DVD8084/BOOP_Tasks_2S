#include "gtest/gtest.h"
#include "arrays.h"
#include "lists.h"
#include "std.h"
#include "dice.h"

using std::cout;

template <typename U, typename V>
void StackTestBase(U structure, V type, unsigned int size)
{
    std::vector <V> elements(size);

    cout << "[PUSHING TEST]\n";
    for (int i = 0; i < size; i++) {
        cout << "Adding next element...\n";
        elements[i] = get_random<V>();
        structure.push(elements[i]);
        ASSERT_EQ(structure.peek(), elements[i]);
        cout << "Element added successfully.\n";
        cout << "Current structure: ";
        structure.print();
    }
    cout << "[TEST END]\n\n";

    cout << "[POPPING TEST]\n";
    for (int i = size; i > 0; i--) {
        ASSERT_EQ(structure.peek(), elements[i - 1]);
        cout << "Popped element ";
        print_data(structure.pop());
        cout << "\nCurrent structure: ";
        structure.print();
    }
    ASSERT_EQ(structure.peek(), get_empty<V>());
    ASSERT_EQ(structure.pop(), get_empty<V>());
    cout << "\n[TEST END]\n\n";

    cout << "[RANDOM FILLING TEST]\n";
    cout << "Filling with random elements...\n";
    structure.fill_random(size);
    cout << "Current structure: ";
    structure.print();
    cout << "Filling with random elements...\n";
    structure.fill_random(size);
    cout << "Current structure: ";
    structure.print();
    cout << "[TEST END]\n";
}

template <typename U, typename V>
void QueueTestBase(U structure, V type, unsigned int size)
{
    std::vector <V> elements(size);

    cout << "[PUSHING TEST]\n";
    for (int i = 0; i < size; i++) {
        cout << "Adding next element...\n";
        elements[i] = get_random<V>();
        structure.push(elements[i]);
        ASSERT_EQ(structure.peek(), elements[0]);
        cout << "Element added successfully.\n";
        cout << "Current structure: ";
        structure.print();
    }
    cout << "[TEST END]\n\n";

    cout << "[POPPING TEST]\n";
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(structure.peek(), elements[i]);
        cout << "Popped element ";
        print_data(structure.pop());
        cout << "\nCurrent structure: ";
        structure.print();
    }
    ASSERT_EQ(structure.peek(), get_empty<V>());
    ASSERT_EQ(structure.pop(), get_empty<V>());
    cout << "\n[TEST END]\n\n";

    cout << "[RANDOM FILLING TEST]\n";
    cout << "Filling with random elements...\n";
    structure.fill_random(size);
    cout << "Current structure: ";
    structure.print();
    cout << "Filling with random elements...\n";
    structure.fill_random(size);
    cout << "Current structure: ";
    structure.print();
    cout << "[TEST END]\n";
}

template <typename U, typename V>
void DequeTestBase(U structure, V type, unsigned int size)
{
    std::vector <V> elements(size * 2);

    cout << "[PUSHING TEST]\n";
    for (int i = 0; i < size; i++) {
        cout << "Adding next element (start)...\n";
        elements[i] = get_random<V>();
        structure.push_start(elements[i]);
        ASSERT_EQ(structure.peek_start(), elements[i]);
        cout << "Element added successfully.\n";
        cout << "Current structure: ";
        structure.print();
    }
    for (int i = size; i < size * 2; i++) {
        cout << "Adding next element (end)...\n";
        elements[i] = get_random<V>();
        structure.push_end(elements[i]);
        ASSERT_EQ(structure.peek_end(), elements[i]);
        cout << "Element added successfully.\n";
        cout << "Current structure: ";
        structure.print();
    }
    cout << "[TEST END]\n\n";

    cout << "[POPPING TEST]\n";
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(structure.peek_start(), elements[size - i - 1]);
        cout << "Popped element ";
        print_data(structure.pop_start());
        cout << " (start)\n";
        cout << "Current structure: ";
        structure.print();
        ASSERT_EQ(structure.peek_end(), elements[size * 2 - i - 1]);
        cout << "Popped element ";
        print_data(structure.pop_end());
        cout << " (end)\n";
        cout << "Current structure: ";
        structure.print();
    }
    ASSERT_EQ(structure.peek_start(), get_empty<V>());
    ASSERT_EQ(structure.pop_start(), get_empty<V>());
    ASSERT_EQ(structure.peek_end(), get_empty<V>());
    ASSERT_EQ(structure.pop_end(), get_empty<V>());
    cout << "\n[TEST END]\n\n";

    cout << "[RANDOM FILLING TEST]\n";
    cout << "Filling with random elements...\n";
    structure.fill_random(size);
    cout << "Current structure: ";
    structure.print();
    cout << "Filling with random elements...\n";
    structure.fill_random(size);
    cout << "Current structure: ";
    structure.print();
    cout << "[TEST END]\n";
}

TEST(ArrayTest, IntStackArrayTest) {
    StackArray <int> arr;
    int i = 0;
    StackTestBase(arr, i, 10);
}

TEST(ArrayTest, CharQueueArrayTest) {
    QueueArray <char> arr;
    char i = 0;
    QueueTestBase(arr, i, 10);
}

TEST(ArrayTest, StringDequeArrayTest) {
    DequeArray <std::string> arr;
    std::string i;
    DequeTestBase(arr, i, 5);
}

TEST(ListTest, FloatStackListTest) {
    StackList <float> arr;
    float i = 0;
    StackTestBase(arr, i, 10);
}

TEST(ListTest, DoubleQueueListTest) {
    QueueList <double> arr;
    double i = 0;
    QueueTestBase(arr, i, 10);
}

TEST(ListTest, VectorIntDequeListTest) {
    DequeArray <std::vector<int> > arr;
    std::vector<int> i;
    DequeTestBase(arr, i, 3);
}

TEST(StdTest, DiceStackStdTest) {
    StackStd <Dice> arr;
    Dice i;
    StackTestBase(arr, i, 5);
}

TEST(StdTest, VectorStringQueueStdTest) {
    QueueStd <std::vector<std::string> > arr;
    std::vector<std::string> i;
    QueueTestBase(arr, i, 5);
}

TEST(StdTest, VectorVectorCharDequeStdTest) {
    DequeStd <std::vector<std::vector<char> > > arr;
    std::vector<std::vector<char> > i;
    DequeTestBase(arr, i, 3);
}

TEST(DiceTest, DiceTest)
{
    std::vector <Dice> dice_set;
    for (int i = 0; i < 2; i++)
    {
        dice_set.emplace_back(6);
    }
    std::vector <double> probabilities;
    for (int i = 0; i < 2; i++)
    {
        probabilities.push_back(i + 1);
    }
    std::vector <Dice> coin_set;
    for (int i = 0; i < 3; i++)
    {
        coin_set.emplace_back(2, probabilities);
    }
    cout << "[SET 1: 2 REGULAR DICE]\n";
    print_probabilities(dice_set);
    cout << "\n[SET 2: 3 UNFAIR COINS]\n[p(0) = 1/3, p(1) = 2/3]\n";
    print_probabilities(coin_set);

}