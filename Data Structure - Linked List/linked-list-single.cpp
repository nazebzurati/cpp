#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
using namespace std;

// main structure of linked list
struct node
{
	string name;
	int age;
	node *next;	
};

// class that store functions related to linked list
class list
{
		private:
		    node *head, *tail;
		
		public:
			// linked list initialization
    		list()
    		{
    			head=NULL;
    			tail=NULL;
    		}
    		
			// add data into linked list
    		void add(string input_name, int input_age)
    		{
    			node *temp=new node;
    			temp->name=input_name;
    			temp->age=input_age;
    			temp->next=NULL;

    			if(head==NULL)
    			{
    				head=temp;
    				tail=temp;
    				temp=NULL;
    			}
    			else
    			{	
    				tail->next=temp;
    				tail=temp;
    			}
    		}
    		
			// display the content of linked list
    		void display()
    		{
    			node *temp=new node;
    			temp=head;

				// do a loop until the linked list ends
    			while(temp!=NULL)
    			{
					// display the data
    				cout<< "Name: " << temp->name << ", " << temp->age << endl;

					// go to the next node
    				temp=temp->next;
    			}
    		}

			// search data from linked list
    		void search(string input_search)
    		{
    			node *temp=new node;
    			temp=head;

				// do a loop until the linked list ends
    			while(temp!=NULL)
    			{
					// display if the variable name is same with the name to be search
					if (temp->name == input_search)
					{
    					cout<< "Name: " << temp->name << ", " << temp->age << endl;
					}

					// go to the next node
    				temp=temp->next;
    			}
    		}
    		
			// delete the first data insert - Queue
    		void delete_fifo()
    		{
    			node *temp=new node;
    			temp=head;
    			head=head->next;
    			delete temp;
    		}
    		
			// delete the last data insert - Stack
    		void delete_lifo()
    		{
    			node *current=new node;
    			node *previous=new node;
    			current=head;
    			while(current->next!=NULL)
    			{
    				previous=current;
    				current=current->next;	
    			}
    			tail=previous;
    			previous->next=NULL;
    			delete current;
    		}

			// update age of a linked list data using its name 
    		void update(string input_search, int input_age)
    		{
    			node *temp=new node;
    			temp=head;

				// do a loop until the linked list ends
    			while(temp!=NULL)
    			{
					// display if the variable name is same with the name to be search
					if (temp->name == input_search)
					{
    					temp->age = input_age;
					}

					// go to the next node
    				temp=temp->next;
    			}
    		}

			// save data into example file
			void save()
			{
				node *temp=new node;
    			temp=head;
				ofstream myfile ("example.txt");
    			
				if (myfile.is_open())
				{
					while(temp!=NULL)
					{
						myfile << temp->name << endl;
						myfile << temp->age << endl;
						temp=temp->next;
					}

					cout << "Linked list data saved.";
					myfile.close();
				}
				else 
				{
					cout << "Unable to open file";
				}
			}

			// load data from saved example file
			void load()
			{
				string line_name, temp;
				int line_age;
				ifstream myfile ("example.txt");
				
				if (myfile.is_open())
				{
					while (!myfile.eof())
					{
						getline (myfile,line_name);

						// check if name is not empty
						if (line_name != "")
						{
							getline (myfile,temp);

							// convert string into int
							istringstream iss (temp);
							iss >> line_age;

							this->add(line_name, line_age);
						}
					}

					cout << "Linked list data loaded.";
					myfile.close();
				}

				else cout << "Unable to open file"; 
			}
};

int choice = 0, age;
string name, search;

int main()
{
	// create a linkedlist named node
	list node;

	while(choice != 9)
	{
		// menu
		cout << "Single Linked List Template for UiTM Students" << endl;
		cout << "1	- Add new data" << endl;
		cout << "2	- Delete first data (First In First Out)" << endl;
		cout << "3	- Delete last data (Last In First Out)" << endl;
		cout << "4	- Display data" << endl;
		cout << "5	- Search data" << endl;
		cout << "6	- Update data" << endl;
		cout << "7	- Save data into file" << endl;
		cout << "8	- Load data from file" << endl;
		cout << "9	- Exit" << endl << endl;
		cout << "Your option: ";
		cin >> choice;

		// double endline to make display more appealing
		cout << endl << endl;

		// selected choice
		if (choice == 1)
		{
			cout << "Your name: ";
			cin.ignore();
			getline(cin, name);
			cout << "Your age: ";
			cin >> age;
			node.add(name, age);
		}
		else if (choice == 2)
		{
			node.delete_fifo();
		}
		else if (choice == 3)
		{
			node.delete_lifo();
		}
		else if (choice == 4)
		{
			node.display();
		}
		else if (choice == 5)
		{
			cout << "Enter name to be search: ";
			cin.ignore();
			getline(cin, search);

			node.search(search);
		}
		else if (choice == 6)
		{
			cout << "Enter name to be edit: ";
			cin.ignore();
			getline(cin, search);
			cout << "Enter new age: ";
			cin >> age;

			node.update(search, age);
		}
		else if (choice == 7)
		{
			node.save();
		}
		else if (choice == 8)
		{
			node.load();
		}

		// double endline to make display more appealing
		cout << endl << endl;
	}

	return 0;
}