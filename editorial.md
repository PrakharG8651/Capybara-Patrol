# Editorial

## Approach 1: Brute Force (Converting number into string and doing operations)

### Algorithm
Simply convert x into binary string, then do padding if needed. After this you can print in blocks of three with prefix as 1 on the leftmost block and 0 for rest.

### Code

<pre><code>#include &lt;bits/stdc++.h&gt;
using namespace std;   

string toBinary(int n){
    string s;
    while(n&gt;0){
        s+=to_string(n%2);
        n/=2;
    }
    while(s.size()%3){
        s=s+"0";
    }
    reverse(s.begin(),s.end());
    return s;
}

int main(){
    int n;
    cin&gt;&gt;n;
    for(int i=0;i&lt;n;i++){
        int x;
        cin>>x;
        string s=toBinary(x);
        for(int j=0;j&lt;s.size()/3;j++){
            if(j==s.size()/3-1){
                cout&lt;&lt;1;
            }
            else{
                cout&lt;&lt;0;
            }
            cout&lt;&lt;s[j*3]&lt;&lt;s[j*3+1]&lt;&lt;s[j*3+2];
        }
    }
}
</code>
</pre>

### Complexity Analysis-

Time Complexity - O(n log(M))</br>
Space Complexity - O(log(M))
where n is the number of inputs and M is the highest input

## Approach 2: Using bitset

Instead of generating binary string we will take the bitset<30> of x and then traverse every 3 bits and printing according to alogrithm.</br>
Binary string generation takes log(x) plus some additional time due string mutation on each step  while bitset takes constant time.

### Code
<pre><code>
#include &lt;bits/stdc++.h&gt;
using namespace std;   

void operate(int x){
    if(x==0){
        cout&lt;&lt;1000;
        return;
    }
    bitset&lt;30&gt; b(x);
    bool start = false;
    for(int i=9;i&gt;-1;i--){
        if(start or (b[i*3+2]+b[i*3+1]+b[i*3])){
            if(!start){
                cout&lt;&lt;1;
                start = true;
            }
            else{
                cout&lt;&lt;0;
            }
            cout&lt;&lt;b[i*3+2]&lt;&lt;b[i*3+1]&lt;&lt;b[i*3];
        }
    }
}

int main(){
    int n;
    cin&gt;&gt;n;
    for(int i=0;i&lt;n;i++){
        int x;
        cin&gt;&gt;x;
        x-=20;
        operate(x);
    }
}
</code></pre>

### Complexity Analysis-

Time Complexity- O(n)</br>
Space Complexity- O(1)