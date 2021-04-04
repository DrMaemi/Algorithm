#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mp make_pair
#define pb push_back
int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		unordered_map<ll,ll> mm;
		ll x;
		unordered_map<ll,ll>::iterator itr;
		for(ll i=0;i<n;i++){
			cin>>x;
			itr = mm.find(x);
			if(itr == mm.end()){
				mm.insert(mp(x,1));
			}else{
				mm[x]++;
			}
		}
		priority_queue<ll> pq;
		for(itr = mm.begin();itr != mm.end();itr++){
			pq.push(itr->second);
		}
		ll qx,qy;
		while(pq.size() > 1){
			qx = pq.top();
			pq.pop();
			qy = pq.top();
		//	cout<<"qx = "<<qx<<endl;
		//	cout<<"qy = "<<qy<<endl;
			pq.pop();
			qx--;
			qy--;
			if(qx > 0){
				pq.push(qx);
			}
			if(qy > 0){
				pq.push(qy);
			}
		}
		if(pq.size() == 0){
			cout<<"0"<<endl;
		}
		else{
	
		ll jr = pq.top();
		cout<<jr<<endl;
	}
		
	}
}