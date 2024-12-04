//Trademark: Gawa ni Lavarro na may tulong ni youtube, google, w3schools, at stackoverflow

#include <iostream>
#include <queue>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

class Person {
public:
    string name;
    int ticket_number;

    Person(string name, int ticket_number) {
        this->name = name;
        this->ticket_number = ticket_number;
    }
};

class Queue {
private:
    queue<Person> q;
    int ticket_counter = 1;

public:
    void enqueue(string name) {
        Person person(name, ticket_counter++);
        q.push(person);
        cout << person.name << " added to the queue with Ticket #" << person.ticket_number << endl;
        cout << "Queue size: " << size() << endl;
    }

    void auto_dequeue() { //After 1 minute lalabas to for the new order of names?? (Sabog na ako sa cheerdance)
        if (!is_empty()) {
            cout << "After 1 minute..." << endl;
            Person front_person = q.front();
            q.pop();
            cout << "Dequeue: " << front_person.name << " received a ticket (Ticket #" << front_person.ticket_number << ")" << endl;
            cout << "Queue size: " << size() << endl;

            if (!is_empty()) {
                Person next_person = q.front();
                cout << "Next in line: " << next_person.name 
                     << " (Ticket #" << next_person.ticket_number << ")" << endl;
            }
        }
    }

    bool is_empty() {
        return q.empty();
    }

    int size() {
        return q.size();
    }

    void peek() {
        if (!is_empty()) {
            Person front_person = q.front();
            cout << "Next in line: " << front_person.name << " (Ticket #" << front_person.ticket_number << ")" << endl;
        } else {
            cout << "The queue is empty." << endl;
        }
    }

    int position(string name) {
        queue<Person> temp = q;
        int pos = 1;

        while (!temp.empty()) {
            if (temp.front().name == name) {
                return pos;
            }
            temp.pop();
            pos++;
        }
        return -1;
    }
};

void auto_dq(Queue& ticket_queue) { //timer para dun sa dequeue iba pa yung variable na "auto_dequeue"
    while (true) {
        this_thread::sleep_for(chrono::minutes(1));
        ticket_queue.auto_dequeue();
    }
}

int main() {
    Queue ticket_queue;
    int choice;
    string name;

    cout << "Welcome to Seventeen's Concert Ticketing System!" << endl;

    thread dequeue_thread(auto_dq, ref(ticket_queue));
    dequeue_thread.detach();

    while (true) {
        cout << "\n1. Enqueue a person\n2. Check your position in the queue\n3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
        case 1: //add name sa queue
            cout << "Enter the name: ";
            cin >> name;
            ticket_queue.enqueue(name);
            break;
        case 2: //checking position
            cout << "Enter your name: ";
            cin >> name;
            int pos;
            pos = ticket_queue.position(name);
            if (pos != -1) {
                cout << name << " is currently at position " << pos << " in the queue." << endl;
            } else {
                cout << "Can't find a person with this name in the queue." << endl;
            }
            break;
        case 3: //If nagexit ng program
            cout << "See you nalang sa next life." << endl;
            return 0;
        default:
            cout << "May options na nga tapos hindi mo pipiliin yung provided? >:/" << endl;
        }
    }

    return 0;
}
