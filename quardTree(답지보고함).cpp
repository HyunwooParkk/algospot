#include <iostream>
#include <string>

using namespace std;


string reverse(string::iterator &it){
	char head=*it;
	it++;
	if(head=='b' || head =='w')
		return string(1,head);
	string upperLeft=reverse(it);
	string upperRight=reverse(it);
	string lowerLeft=reverse(it);
	string lowerRight=reverse(it);

	return string("x").append(lowerLeft).append(lowerRight).append(upperLeft).append(upperRight);
}

int main(void)
{
	int test_case;
	string picture;
	cin>>test_case;
	if(test_case<0 || test_case>50)
		exit(-1);

	for(int i=0; i<test_case; i++)
	{
		cin>>picture;
		if(picture.size()>1000)
			exit(-1);

		string::iterator it=picture.begin();

		cout<<reverse(it) <<endl;
	}
	return 0;
}


