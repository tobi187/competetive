#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> nums)
{
	int c = 0;
	queue<int> q;
	for (int a : nums)
		q.push(a);
	while (q.size() > 1)
	{
		int e1 = q.front();
		q.pop();
		int e2 = q.front();
		q.pop();
		c += e1;
		c += e2;
		q.push(e1 + e1);
	}
	return c;
}

int maximumScore(int a, int b, int c)
{
	// vector<int> arr{a, b, c};
	int sc = 0;
	priority_queue<int> pq;
	pq.push(a);
	pq.push(b);
	pq.push(c);

	while (pq.size() > 1)
	{
		int f = pq.top() - 1;
		pq.pop();
		int s = pq.top() - 1;
		pq.pop();
		if (f > 0)
			pq.push(f);
		if (s > 0)
			pq.push(s);
		sc++;
	}

	return sc;
}

int findKthLargest(vector<int> nums, int k)
{
	set<int> s;
	priority_queue<int> pq;
	for (int nn : nums)
		pq.push(nn);
	for (int i = 1; i < k; i++)
		pq.pop();
	return pq.top();
}

class Compare
{
public:
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		return !(abs(a.first - a.second) <= (b.first - b.second));
	}
};

vector<int> findClosestElements(vector<int> arr, int k, int x)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
	for (int aa : arr)
		pq.push(make_pair(aa, x));
	vector<int> result(k);
	for (int i = 0; i < k; i++)
	{
		result[i] = pq.top().first;
		pq.pop();
	}
	sort(result.begin(), result.end());

	return result;
}

int indexEqualsValueSearch(vector<int> &arr)
{
	int s = 0;
	int e = arr.size() - 1;
	while (s <= e)
	{
		int mid = (s + e) / 2;
		if (arr[mid] == mid)
			return mid;
		if (arr[mid] < mid)
			s = mid + 1;
		else
			e = mid - 1;
	}
	return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k, x;
	cin >> n;

	vector<int> arr(n);
	for (int &a : arr)
		cin >> a;
	cout << indexEqualsValueSearch(arr);
}