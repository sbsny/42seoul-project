 #include<iostream>
  #include<map>
  using namespace std;
  int main()
  {
        map<int, char> mp;
	mp.insert({ 53,'A'  });
	mp.insert({ 12,'Z' });
	mp.insert({ 33,'K' });
	mp.insert({ 66,'F' });
	for (auto it = mp.begin(); it != mp.end(); it++)
	{
		cout << (*it).first << " " <<(*it).second << endl;
	}
        auto it = mp.lower_bound(54);
	cout << "Lower bound is ";
	cout << (*it).first << " " << (*it).second << endl;

	it = mp.lower_bound(67);
	it--;
	cout << "Lower bound is  ";
	cout << (*it).first << " " << (*it).second;
	it = mp.lower_bound(66);
	cout << "\nLower bound is  ";
	cout << (*it).first << " " << (*it).second;
	return 0;
}
