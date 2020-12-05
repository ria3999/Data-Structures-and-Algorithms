#include <iostream>
#include <cstdlib>
using namespace std;
struct node {
	bool isWord;
	node *next[26];
};

node* newnode()
{
	node *temp = (node*) malloc(sizeof(node));
	temp->isWord = false;
	for (int i = 0; i < 26; ++i)
	{
		temp->next[i] = NULL;
	}
	return temp;
}

void insert(node *root, string s)
{
	node *temp = root;
	for (int i = 0; i < s.length(); ++i)
	{
		if(temp->next[s[i]-'a'] == NULL)
		{
			temp->next[s[i]-'a'] = newnode();
		}
		temp = temp->next[s[i]-'a'];
	}
	temp->isWord = true;
}

bool search(node *root, string s)
{
	node *temp = root;
	for (int i = 0; i < s.length(); ++i)
	{
		if(temp->next[s[i]-'a'] == NULL)
		{
			return false;
		}
		temp = temp->next[s[i]-'a'];
	}
	return temp->isWord;
}

int main()
{
	node *root = newnode();
	int n;
	cin>>n;
	string s;
	for (int i = 0; i < n; ++i)
	{
		cin>>s;
		insert(root, s);
	}
	int q;
	cin>>q;
	for (int i = 0; i < q; ++i)
	{
		cin>>s;
		if(search(root, s))
			cout<<s<<" is in trie\n";
		else
			cout<<s<<" is not in trie\n";
	}
}