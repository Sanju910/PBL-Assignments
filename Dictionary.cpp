#include <iostream>
using namespace std;

class node {
  public:
  string word;
  string meaning;
  struct node *left, *right;
  node()
  {
      left=NULL;
      right=NULL;
  }
};
class BST
{
  public:
  node *root;
  BST()
  {
      root=NULL;
  }
  // Create a node
  node *newNode(string key,string m) 
  {
  node *temp = new node();
  temp->word = key;
  temp->meaning = m;
  return temp;
  }
  // Inorder Traversal
 void inorder(struct node *root)
  {
  if (root != NULL)
   {
    // Traverse left
    inorder(root->left);
    // Traverse root
    cout <<"WORD: "<< root->word<<endl;
    cout<<"MEANING: "<<root->meaning<<endl<<endl;
    // Traverse right
    inorder(root->right);
  }
 }
 //Search a node
 int find(node *root, string data)
{
    if(root==NULL)
        return 0;
    if(root->word>data)
        return find(root->left,data);
    else if(root->word<data)
        return find(root->right,data);
    else if(root->word==data){
        cout<<data<<" : "<<root->meaning;
        return 1;
    } 
    return 0;
} 
//Search a node
node* IterativeSearch(string val)
  	{
  		if(root==NULL)
  		{
  			return root;
  		}
  		else
  		{
  			node *temp=root;
  			while(temp!=NULL)
  			{
  				if(val==temp->word)
  			{
  				return temp;
  			}
  			else if(val<temp->word)
  			{
  				temp=temp->left;
  			}
  			else
  			{
  				temp=temp->right;
  			}

  			}
  		}
  		return NULL;
  	}
// Insert a node
node *insert(node *node, string word, string meaning) {
 
  if (node == NULL) 
  return newNode(word,meaning);
  if(find(node,word))
  {
      cout<<"\n\nWord already exists\n\n";
      return node;
  }
  if (word < node->word)
    node->left = insert(node->left, word, meaning);
  else
    node->right = insert(node->right, word,meaning);

  return node;
}
// Find the inorder successor
node *minValueNode( node *n)
 {
  node *current=n;
  while (current && current->left != NULL)
    current = current->left;
  return current;
}
// Deleting a node
node *deleteNode( node *root, string key) {

  if (root == NULL) return root;

  if (key < root->word)
    root->left = deleteNode(root->left, key);
  else if (key > root->word)
    root->right = deleteNode(root->right, key);
  else {

    if (root->left == NULL) {
       node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
       node *temp = root->left;
      free(root);
      return temp;
    }
    node *temp = minValueNode(root->right);
    root->word = temp->word;
    root->right = deleteNode(root->right, temp->word);
  }
  return root;
}
};
// Driver code
int main() 
{
   BST b;
   int ch;
   do
   {
       cout<<"******************************************************************"<<endl;
       cout<<"Enter the operation to be performed: "<<endl;
       cout<<"1:Insert the Word"<<endl;
       cout<<"2:Displaying the dictionary"<<endl;
       cout<<"3:Delete the word in the dictionary"<<endl;
       cout<<"4:Updating the meaning"<<endl;
       cout<<"Press 0 to Exit"<<endl;
       cout<<"******************************************************************"<<endl;
       cin>>ch;
       node *p=new node();
       switch(ch)
       {
           case 1:
           {
               cout<<"******************************************************************"<<endl;
               string word,meaning;
               cout<<"Enter the word and its meaning: ";
               cin>>word>>meaning;
               b.root=b.insert(b.root,word,meaning);
               cout<<"******************************************************************"<<endl;
               break;
           }
           case 2:
           {
               cout<<"******************************************************************"<<endl;
               b.inorder(b.root);
               cout<<"******************************************************************"<<endl;
               break;
           }
           case 3:
           {
               cout<<"******************************************************************"<<endl;
               string word;
               cout<<"Enter the word to be deleted: ";
               cin>>word;
               b.root=b.deleteNode(b.root,word);
               cout<<"Word Deleted"<<endl;
               cout<<"******************************************************************"<<endl;
               break;
           }
           case 4:
           {
               cout<<"******************************************************************"<<endl;
               string word,meaning;
               cout<<"Enter the word to be updated: ";
               cin>>word;
               node *temp;
               temp=b.IterativeSearch(word);
               cout<<"Enter the new word and meaning: ";
               cin>>word>>meaning;
               temp->word=word;
               temp->meaning=meaning;
               cout<<"Updated"<<endl;
               cout<<"******************************************************************"<<endl;
               break;
           }
       }

   }while(ch!=0);
   cout<<"END OF THE CODE,THANK YOU"<<endl;
   return 0;
}
