# codeforce_round_496_div3

## [tourist](http://codeforces.com/blog/entry/60511)
### C_Summarize to the Power of Two
题面：
给出n个数字，若想使其满足对于其中任意一个数字a均存在另一个数字b是的a+b是2的平方数，
最少需要删去几个数字。
* map[input[i]]++;
* pairNum=(1<<[1:30])-input[i];
* if map[pairNum]>1 or map[pairNum]=1 && pairNum!=input[i]
* then continue
* else delete_num++;
```
int n;
cin >> n;
vector<int> a(n);
map<int,int> c;
forn(i, n) {
    cin >> a[i];
    c[a[i]]++;
}
int ans = 0;
forn(i, n) {
    bool ok = false;
    forn(j, 31) {
        int x = (1 << j) - a[i];
        if (c.count(x) && (c[x] > 1 || (c[x] == 1 && x != a[i])))
            ok = true;
    }
    if (!ok)
        ans++;
}
cout << ans << endl;
```
### D_Polycarp and Div 3
题面：给出一个字符串，其由n个数字组成，其n在2~2*10^5之间，将其分成多个字字符串。
我们需要找出能被3乘除的子字符串的数量，并求出最大值
* fin[r] 表示prefix 之和余数是r的index
* z[i] 表示前i个数值里面，满足题意的最大值
* z[i] = z[i-1]; 表示若最后一个数字不能和前面组合三的倍数
* z[i] = max(z[i], z[fin[r]] + 1); 表示update z[i]
理解： 当前r表示从0到i之和的余数，而fin[r]还没更新，也就是说找到上一个prefix
之和的余数也是r的，那么从fin[r]到i之间的和是3的整数倍，所以可以看做
```
string s;
cin >> s;
int n = s.length();

int r = 0;
vector<int> fin(3, -1);
fin[0] = 0;

vector<int> z(n + 1);
for (int i = 1; i <= n; i++) {
    r = (r + s[i - 1] - '0') % 3;
    z[i] = z[i - 1];
    if (fin[r] != -1)
        z[i] = max(z[i], z[fin[r]] + 1);
    fin[r] = i;
}

cout << z[n] << endl;
```

### E1
题面：
给出一段长度为n的排列，(n=5有1,3,2,4,5,都必须小于等于5)，在给出一个m，
找出所有的子序列(and count)，使得子序列的中位数(如果长度为偶数，那么中位数是中间靠左那个)小于等于m

题解：

假设中位数是median，位置是index

因为我们不关心别的数比median大或者小多少，因此我们将比median大的视为1，比其小的视为-1，相等视为0
(因为是排列，不会出现多个相同的median)

我们使用一个前缀数组 **sum[i]** 表示(# of greater than median)-(# of less than median)
并在此时建立一个map<int,int>，每次循环让map[sum[i]]++

当i>= index时，即我们找到了median，故开始找使得median成为中位数的连续子序列。

不妨设现在的sum[i]=Q，为了找到一个连续子序列时候median为中位数，必须保证比median大和小的数相同，
什么时候相同呢？即sum[X]也等于Q的时候，从X到i正好是一个以median为中位数的子序列，所以我们要找找有几个sum[X]=Q.
这是map[sum[i]]就派上用场了，map[sum[i]]就是有多少个sum[X]=Q。

另外这里我们只考虑了median作为整整好好的中位数，median还可以作为偶数序列的中间靠左那个元素，也就是说

(比median大的元素的#)-(比median小的元素的#)=1 or 0;

我们可以用map[sum[i]-1]来表示(-1代表大于median的数量可以少一个)
(试想当前为sum[i]=10，map[10]就是找到上次在10的数，map[9]就是找到上次在9的那个数
比10少了一个大于median的数)

code:
```
int n, m;
cin >> n >> m;
vector<int> p(n);
forn(i, n)
    cin >> p[i];
map<int,int> c;
c[0] = 1;
bool has = false;
int sum = 0;
long long ans = 0;
for (int r = 0; r < n; r++) {
    if (p[r] < m)
        sum--;
    else if (p[r] > m)
        sum++;

    if (p[r] == m)
        has = true;
    if (has)
        ans += c[sum] + c[sum - 1];
    else
        c[sum]++;
}
cout << ans << endl;
```

### E2 !!!!
题面:
大致与上面相同，不过n只约束了数组的长度，不约束大小和是否重复
题解：

define a function `greaterCount(m)`表示# of subarray with the median >=m)
then ans we want is `greaterCount(m)-greaterCount(m+1)`

think a subaray `a`'s median is >= m, if and only if (# of `>=m` > # of `<`)

now we have a array `x`, x[i]=1 if input[i]>m,x[i]=-1 if input[i]<m

then the median of `a[l:r]` is >= m ,if and only if sum(x[l:r])>0



