/*UNLESS OTHERWISE INDICATED, ALL CODE IN HEADER CLASS WAS CREATED BY STORI WILLIAMS*/

//Include Libraries
#include "Ship.h"

#ifndef LINKINGLIST__H
#define LINKINGLIST__H

#pragma region Attributes

struct Link
{
	Ship contentInfo; //Points to the content's information location based on the user's selection (reason why it is a pointer) 
	Link * ptrNextLink; //Points to the next link in the list
};


//Variables
Link * startLink; //The start link of the list of links	
Link * currLink; //Keeps track of the current link
Link * newLink; //Create a new instance of the link list
fstream LinkFile; //The link list file object (for input and output)



#pragma endregion

#pragma region Behaviors


//Function Declarations
void CreateNewLinkList(); //Purpose: Creates a new link list by setting the start link's pointer to null
void AddToList(); //Purpose: Adds a link to the list
void AddToList(Ship); //Purpose: Adds an existing link to the list 
void DeleteList(); //Purpose: Delete all the links from the list
void DisplayList(string); //Purpose: Displays all for the links in the list (depending on content type)
void SaveListToFile(); //Purpose: Save current link list to the file
bool UpdateList(string); //Purpose: Updates the contents of a link in the list (depending on search type)
void ReadFileForList();  //Purpose: Reads the contents in the file, then saves information into a whole new link list
void DeleteLink(); //Purpose: Deletes a link from the link list 




////Function Definitions
void DeleteLink()
{
	string user_input; //Keeps track of the user's input

	//Prompt user to enter an item name to remove from the list
	cout << "Please enter the name of the item you would like to remove (i.e ProductA): \n";
	DisplayList("Name");
	cin >> user_input;

	//Set current link to the start link
	currLink = startLink;

	Link* prevLink = currLink;

	while (currLink != NULL) //While there are link contents to look through
	{
		

		//if (currLink->contentInfo.getName() == user_input) //Todo if the user's input is found
		//{
		//	Link* delLink = currLink;

		//	if (currLink == startLink) //If the node is at the beginning of the link list
		//	{
		//		startLink = currLink->ptrNextLink;
		//		
		//	}
		//	else if (currLink->ptrNextLink == NULL) //If the node is at the end of the link list
		//	{
		//		prevLink->ptrNextLink = NULL;
		//	

		//	}
		//	else //If the node is in the middle of the link list 
		//	{
		//		prevLink->ptrNextLink = currLink->ptrNextLink;
		//	
		//	}

		//	delete delLink; //Delete the current link
		//	return;

		//}
		//else
		//{
		//	prevLink = currLink;
		//	currLink = currLink->ptrNextLink; //Set the current item link to the next link in the link list
		//}
		
		
	}
	



};
void CreateNewLinkList()
{
	//Create a new start link
	startLink = new Link;

	//Set content and ptrto's values to nothing/null
	startLink = NULL;
};
void AddToList()  
{
	Ship contentObject; //Create a new object
	//contentObject.AddNewProduct(); //Call function to create the object
	newLink = new Link; //Create a new link
	newLink->contentInfo = contentObject; //Set the content of the link to the new object
	newLink->ptrNextLink = startLink; //Set the pointer to the next link to the previous start link
	startLink = newLink; //Set the new link as the current new link


};

void AddToList(Ship contentObject)
{
	
	newLink = new Link; //Create a new link
	newLink->contentInfo = contentObject; //Set the content of the link to the new object
	newLink->ptrNextLink = startLink; //Set the pointer to the next link to the previous start link
	startLink = newLink; //Set the new link as the current new link


};

void DeleteList() 
{

	Link* delLink; //Keeps track of the link to be deleted
	while (startLink != NULL) {	//While there are still links to be deleted 				
		delLink = startLink; //Set the deleted link pointer to the current start link
		startLink = startLink->ptrNextLink; //Set the start link to the location of the next link
		delete delLink; //Delete the 'to be deleted' link			
	}

};

void DisplayList(string content_type) 
{

	int product_num = 0;
	currLink = startLink; //Set the current link to the start link

	if (content_type == "Name")
	{
		//DISPLAY CONTENTS (name) FROM THE LINK LIST
		product_num = 1; //Set product num to 1

		while (currLink != NULL) //While there are link contents to look through
		{
			//cout << product_num << ". " << currLink->contentInfo.getName() << endl; //Display the name of each product
			currLink = currLink->ptrNextLink; //Set the current item link to the next link in the link list
			product_num++; //Increment product num
		}

	}
	else if (content_type == "All")
	{


		while (currLink != NULL) //While there are link contents to look through
		{
			//Display information of contact
			/*cout << "Name: " << currLink->contentInfo.getName() << endl;
			cout << "Calories: " << currLink->contentInfo.getCalories() << endl;
			cout << "Cost: " << currLink->contentInfo.getCost() << endl;
			cout << "Sales: " << currLink->contentInfo.getSalesPrice() << endl;
			cout << "QOH: " << currLink->contentInfo.getQOH() << endl;*/
			cout << endl;
			currLink = currLink->ptrNextLink; //Set the current link to the next link in the link list
		}



	}


};

void SaveListToFile() 
{
	//TODO: MAKE FUNCTIONAL WRITE LIST TO BINARY FILE
	//int numLink = 0; //Keeps track of the number of Links Created
	//currLink = startLink; //Set the current link to the start link
	//LinkFile.open("Ship.dat", ios::out | ios::binary); //Open the link list file

	//while (currLink != NULL) //While there are link contents to look through
	//{
	//	numLink++; //Increment the Link NUmber count
	//	currLink = currLink->ptrNextLink; //Set the current link to the next link in the link list
	//}

	//LinkFile.write(reinterpret_cast<char*>(&numLink), sizeof(numLink));

	//currLink = startLink; //Set the current link to the start link
	//while (currLink != NULL) //While there are link contents to look through
	//{
	//	//Append the new link to the file (convert information to binary)
	//	LinkFile.write(reinterpret_cast<char*>(&currLink->contentInfo), sizeof(currLink->contentInfo)); //Product Object
	//	currLink = currLink->ptrNextLink; //Set the current link to the next link in the link list

	//}

	//LinkFile.close(); //Close the link list file


};

bool UpdateList(string search_type)
{

	
	string search_info; //Keeps track of the search info
	currLink = startLink; //Set the current item link to the start item
	bool isSearchNotFound = true; //Set to true the fact that the search criteria has not been found
			if (search_type == "Name")
			{

				// Prompt user to select a product to update (enter name)
				cout << "Select a product to update (Please Enter Name, example - ProductA): " << endl;

				//Call function to display content from the link list (name)
				DisplayList("Name");

				//Prompt user for input
				cin >> search_info;
				
				while (currLink != NULL) //While there are link contents to look through
				{

					//if (search_info == currLink->contentInfo.getName()) //To do if the a product in the list is selected 
					//{
					//	//Call function to prompt user to modify information about the product
					//	currLink->contentInfo.ModifyProduct();

					//	//Success Message
					//	cout << "The product has been updated successfully.\n\n";

					//	//Set isSearchNotFound to false
					//	isSearchNotFound = false;

					//	break;
					//}
					//else
					//{
					//	currLink = currLink->ptrNextLink; //Set the current item link to the next link in the link list
					//}



				}


				if (isSearchNotFound) //If the search information has not been found
				{
					cout << "Please enter the correct name of the product that you would like to update.\n\n"; //Error Message
				}


			}

			return isSearchNotFound;
			
};

void ReadFileForList()
{

	//TODO: MAKE FUNCTIONAL READ LIST TO BINARY FILE

	//int numLink = 0; //Keeps track of the number of links that should be created
	//Ship contentObject; //Create a new object
	//LinkFile.open("Ship.dat", ios::in | ios::out | ios::app | ios::binary); //Open the link list file


	//if (!LinkFile) //If file does not exist, create it
	//{
	//	cout << "File does not exist, creating new file...\n";

	//	LinkFile.open("Ship.dat", ios::in | ios::out | ios::app | ios::binary | ios::trunc); //Open the link list file
	//	LinkFile.write(reinterpret_cast<char*>(&numLink), sizeof(numLink));
	//	LinkFile << "\n";
	//	LinkFile.close(); //Close the link list file
	//}
	//else 
	//{
	//	if (LinkFile.peek() == ifstream::traits_type::eof())
	//	{
	//		LinkFile.write(reinterpret_cast<char*>(&numLink), sizeof(numLink));
	//	}
	//	LinkFile << "\n";
	//	LinkFile.close(); //Close the link list file
	//}


	//
	//LinkFile.open("Ship.dat", ios::in | ios::out | ios::app | ios::binary); //Open the link list file
	//LinkFile.seekg(0);
	//LinkFile.read(reinterpret_cast<char*>(&numLink), sizeof(numLink));

	//

	////for (int i = 0; i < numLink; i++); //To do while not at the end of the file
	//{
	//	LinkFile.read(reinterpret_cast<char*>(&contentObject), sizeof(contentObject));

	//	if (contentObject.getName() != "")
	//	{
	//		newLink = new Link; //Create a new link
	//		newLink->contentInfo = contentObject;
	//		newLink->ptrNextLink = startLink; //Set the pointer to the next link to the previous start link
	//		startLink = newLink; //Set the new link as the current new link


	//	}
	//	else if (contentObject.getName() == "")
	//	{
	//		LinkFile.close(); //Close the link list file
	//		return;
	//	}
	//
	//

	//
	//

	//} 

	//LinkFile.close(); //Close the link list file



};



#pragma endregion

#endif // !LINKINGLIST__H


/*TODO: Change code that was originally with previous program to fit information in new program*/