#include <iostream>
#include <string>

#include "p3.h"

using namespace std;

Info::Info() {
    this->name = "No Name Set";
    this->value = "No Value Set";
    this->next = nullptr;
}

Info::Info(std::string name, std::string value, Info *next) {
    this->name = name;
    this->value = value;
    this->next = next;
}

Contact::Contact() {
    this->first = "No First Set";
    this->last = "No Last Set";
    this->next = nullptr;
    this->headInfoList = nullptr;
}

Contact::Contact(std::string first, std::string last, Contact *next) {
    this->first = first;
    this->last = last;
    this->next = next;
    this->headInfoList = nullptr;
}

ContactList::ContactList() {
    this->headContactList = nullptr;
    this->count = 0;
}

int ContactList::getCount() {
    return this->count;
}

// print the specified contact and its information
// 1. return false and print nothing if the contact is not in the list
// 2. otherwise return true and print the contact
bool ContactList::printContact(std::ostream &os, std::string first, std::string last) {
   Contact *temp = headContactList;
   bool here = false;
   while(temp != nullptr) 
   {
       if(temp->first == first && temp->last == last) 
       {
           Info *temp2 = temp->headInfoList;
           here = true;
           os << "Contact Name: " << temp->first << " " << temp->last << endl;
           while (temp2 != nullptr) 
           {
               os << temp2->name << " | "<< temp2->value << endl;
               temp2 = temp2->next;
           }
           return true;
       }
       temp = temp->next;
   }

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
    if(here == false)
    {
        return false;
    }

    return false;
}

// print all contacts and their information
// print nothing if the list is empty
    // print everything both first and last name and the info belonging to each
    // first make a while to go through the list
    // then print the name "first-last"
    // then print info accordingly
void ContactList::print(std::ostream &os) {
    Contact *temp = headContactList;
    while(temp != nullptr)
    {
        os << "Contact Name: " << temp->first << " " << temp->last << endl;
        Info *temp2 = temp->headInfoList;
        while (temp2 != nullptr) 
        {
            os << "\t" << temp2->name << " | "<< temp2->value << endl;
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}

// add a contact to the back of the list
// 1. return false and do nothing if the contact is already in the list
// 2. otherwise return true and add the contact to the back of the list
// - do not forget to update count
bool ContactList::addContact(std::string first, std::string last) {
    Contact *temp = headContactList;
    Contact *temp2 = headContactList;
    while(temp != nullptr)
    {
        if(temp->first == first && temp->last == last) 
        {
           // Number 1
            return false;
        }
        temp = temp->next;
    }

    //creating a new node for headContactList
    Contact *n = new Contact(first, last);
    if(temp2 == nullptr)
    {
        //asigning it to the first spot if its empty
        temp2 = n;  

    }
    else
    {
        //assigning it to the first empty spot
        Contact *cur = temp2;
        while(cur->next != nullptr)
        {
            cur = cur->next;
        }
        cur->next = n;

    }

    this->count++; 
    headContactList = temp2;
    return true;
}

// add info to the back of a contact's info list
// 1. return false and do nothing if the contact is not in the list
// 2. if the infoName is already in the info list, update the infoValue and return true
// 3. otherwise add the info to the back of the contact's list and return true
bool ContactList::addInfo(std::string first, std::string last, std::string infoName, std::string infoVal) {
    Contact *temp = headContactList;
    Info *n = new Info(infoName, infoVal);
    bool cfound = false;
    // goes into headContactList 
    while(temp != nullptr)
    {
        //tries to find an existing contact
        if(temp->first == first && temp->last == last) 
        { 
            //turns true once found
            cfound = true;
            //goes into headInfoList
            if(temp->headInfoList == nullptr)
            {
                temp->headInfoList = n;
                return true;
            }
            Info *prev = temp->headInfoList;
            Info *cur = temp->headInfoList->next;
            if(prev->name == n->name)
            {
                prev->value = n->value;
                return true;
            }
            while(cur != nullptr)
            {   
                //tries to find existing infoname
                if(cur->name == n->name)
                {
                    //NUMBER 2
                    //turns true once found
                    //proceeds to update existing name with a new value then returns true
                    cur->value = n->value;
                    return true;
                }
                cur = cur->next;
                prev = prev->next;
            }
            // breaks out of while if found but info name doesnt exist

            prev->next = n;
            return true;

            break;
        }
        temp = temp->next;

    }
    // no contact was found so returns false NUMBER 1
    if(cfound == false)
    {
        return false;
    }

    return true;
}

// add a contact to the list in ascending order by last name
//     if last names are equal, then order by first name ascending
// 1. return false and do nothing if the contact is already in the list
// 2. otherwise return true and add the contact to the list
// - do not forget to update count
// - a compare method/function is recommended
bool ContactList::addContactOrdered(std::string first, std::string last) {
    Contact *temp = headContactList;
    Contact *temp2 = headContactList;
    //checks if the contact is already in the list
    while(temp != nullptr)
    {
        if(temp->first == first && temp->last == last) 
        {
           // Number 1
            return false;
        }
        temp = temp->next;
    }

    this->count++;
    //creating a new node for headContactList
    Contact *n = new Contact(first, last);
    /* Current cases
            in the first spot, in the middle or at the end
            if the first two have the same last check first and make it the new head or put it after
            if the last names are the same check the first names to see if it goes before or after the cur and check for similar last names after;
            if the last are the same and cur == nullptr put it at the end*/
    if(temp2 == nullptr)
    {
        //asigning it to the first spot if its empty
        // << "1" <<endl;
        temp2 = n;
        headContactList = temp2; 
        return true;
    }
    Contact *prev = headContactList;
    Contact *cur = headContactList->next;
    //checks for the second case
    if(n->last <= prev->last)
    {
        if(n->last == prev->last)
        {
            if(n->first < prev->first)
            {
                // << "2a" <<endl;
                n->next = prev;
                headContactList = n;
                return true;
            }
            else
            {
                // << "2b" <<endl;
                n->next = cur;
                prev->next = n;
                headContactList = prev;
                return true;
            }
        }
        else
        {
            // << "2c" << endl;
            n->next = prev;
            headContactList = n;
            return true;
        }
        // << "2d" << endl;
        prev->next = n;
        n->next = cur;
        return true;
    }
    // checks third and fourth case;
    else
    {
        while(cur != nullptr)
        {
            if(n->last <= cur->last)
            {
                if(n->last == cur->last)
                {
                    while(n->last == cur->last)
                    {
                        if(n->first < cur->first)
                        {
                            n->next = cur;
                            prev->next = n;
                            //headContactList = prev;
                            return true;
                        }
                        else
                        {
                            prev = cur;
                            cur = cur->next;
                        }
                    }
                    n->next = cur;
                    prev->next = n;
                    //headContactList = prev;
                    return true;
                }

                else if(n->last < cur->last )
                {
                    n->next = cur;
                    prev->next = n;
                    //headContactList = prev;
                    return true;
                }
            }
            prev = cur;
            cur = cur->next;
        }
        prev->next = n;
        n->next = cur;
        return true;
    }
    return true;
}

// add info to a contact's info list in ascending order by infoName
// 1. return false and do nothing if the contact is not in the list
// 2. if the infoName is already in the info list, update the infoValue and return true
// 3. otherwise add the info to the contact's list and return true
bool ContactList::addInfoOrdered(std::string first, std::string last, std::string infoName, std::string infoVal) {
    Contact *temp = headContactList;
    Info *n = new Info(infoName, infoVal);
    bool cfound = false;
    // goes into headContactList 
    while(temp != nullptr)
    {
        //tries to find an existing contact
        if(temp->first == first && temp->last == last) 
        { 
            //turns true once found
            cfound = true;
            //goes into headInfoList
            if(temp->headInfoList == nullptr)
            {
                //<<"here" <<endl;
                temp->headInfoList = n;
                return true;
            }
            Info *prev = temp->headInfoList;
            Info *cur = temp->headInfoList->next;
            if(n->name < prev->name)
            {
                n->next = prev;
                temp->headInfoList = n;
                return true;
            }
            else{
                while(cur != nullptr)
                {   
                    //tries to find existing infoname
                    if(n->name <= cur->name)
                    {
                        if(cur->name == n->name) 
                        {
                            cur->value == infoVal;
                            return true;
                        }
                            // << "1" << endl;
                            n->next = cur;
                            prev->next = n;
                            return true;
                    }
                    prev = cur;
                    cur = cur->next;
                }
            }
            // << "2" << endl;
            prev->next = n;
            n->next = cur;
            return true;

        }
        temp = temp->next;

    }
    // no contact was found so returns false NUMBER 1
    if(cfound == false)
    {
        return false;
    }


    
    return true;
}

// remove the contact and its info from the list
// 1. return false and do nothing if the contact is not in the list
// 2. otherwise return true and remove the contact and its info
// - do not forget to update count
bool ContactList::removeContact(std::string first, std::string last) {
    Contact *temp = headContactList;
    Contact *prev = headContactList;
    Contact *cur = headContactList->next;
    if(first == temp->first && last == temp->last)
    {
        while(temp->headInfoList != nullptr)
        {
            Info *del = temp->headInfoList;
            temp->headInfoList = temp->headInfoList->next;
            delete del;
        }
        Contact* del = temp;
        temp = temp->next;
        delete del;
        this->count--;
        return true;
    }
    else
    {
        bool found = false;
        while(cur != nullptr)
        {
            if(first == cur->first && last == cur->last)
            {
                found = true;
                while(cur->headInfoList != nullptr)
                {
                    Info *del = cur->headInfoList;
                    cur->headInfoList = cur->headInfoList->next;
                    delete del;
                }
                prev->next = cur->next;
                delete cur;
                this->count--;
                return true;
            }
            cur = cur->next;
            prev = prev->next;
        }
        if(found == false)
        {
            return false;
        }
    }


    return true;
}

// remove the info from a contact's info list
// 1. return false and do nothing if the contact is not in the list
// 2. return false and do nothing if the info is not in the contact's info list
// 3. otherwise return true and remove the info from the contact's list
bool ContactList::removeInfo(std::string first, std::string last, std::string infoName) {
    Contact *temp = headContactList;  
    bool found = false;
    while(temp != nullptr) 
    {
        if(temp->first == first && temp->last == last)
        {
            found = true;
            Info *prev = temp->headInfoList;
            Info *cur = temp->headInfoList->next; 
            if(prev->name == infoName)
            {
                Info *del = temp->headInfoList;
                temp->headInfoList = temp->headInfoList->next;
                delete del;
                return true;
            }
            else
            {
                while(cur != nullptr)
                {
                    if(cur->name == infoName)
                    {
                        
                        prev->next = cur->next;
                        delete cur;
                        return true;
                    }
                    cur = cur->next;
                    prev = prev->next;
                }
                return false;
            }
        }
        temp = temp->next;
    }

    if(found == false)
    {
        return false;
    }
    return true;
}

// destroy the list by removing all contacts and their infos
ContactList::~ContactList() {
    Contact *temp = headContactList;
    while(temp != nullptr)
    {
        while(temp->headInfoList != nullptr)
        {
            Info *del = temp->headInfoList->next;
            delete temp->headInfoList;
            temp->headInfoList = del;
            
        }
        Contact *del = temp->next;
        delete temp;
        temp = del;
        
    }
    this->count = 0;
}

// deep copy the source list
// - do not forget to update count
ContactList::ContactList(const ContactList &src) {
    //Contact *n = src.headContactList->next;
    //Contact *prev = headContactList;





}

// remove all contacts and their info then deep copy the source list
// - do not forget to update count
const ContactList &ContactList::operator=(const ContactList &src) {
    //if (this != &src) {

    //}
    return *this;
}
