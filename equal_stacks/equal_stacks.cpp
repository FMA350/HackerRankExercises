#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'equalStacks' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY h1
 *  2. INTEGER_ARRAY h2
 *  3. INTEGER_ARRAY h3
 */
 
 int height(vector<int> v)
 {
     auto h = 0;
    for(int el : v)
    {
        h+=el;
    }
    return h;
 }
 
int popAndGet(vector<int>& v)
{
    auto value = v.front();
    // cout << "size: " << v.size() << endl;
    v.erase(v.begin());
    // cout << "new size: " << v.size() << endl;

    return value;
}

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3)
{
    auto h1h = height(h1); 
    auto h2h = height(h2); 
    auto h3h = height(h3);
    // cout << "h: " << h1h << " - h2 " << h2h << " - h3 " << h3h << endl;
    
    
    while (true)
    {
        if(h1h == h2h && h2h == h3h)
        {
            break;
        }
        auto min = std::min(std::min(h1h,h2h), h3h);
        cout << min << endl;
        if(h1h > min)
        {
            h1h = h1h - popAndGet(h1);
        }
        if(h2h > min)
        {
            h2h = h2h - popAndGet(h2);
        }
        if(h3h > min)
        {
            h3h = h3h - popAndGet(h3);
        }
        // cout << "h1: " << h1h << " - h2 " << h2h << " - h3 " << h3h << endl;
        
    }
    return h1h;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n1 = stoi(first_multiple_input[0]);

    int n2 = stoi(first_multiple_input[1]);

    int n3 = stoi(first_multiple_input[2]);

    string h1_temp_temp;
    getline(cin, h1_temp_temp);

    vector<string> h1_temp = split(rtrim(h1_temp_temp));

    vector<int> h1(n1);

    for (int i = 0; i < n1; i++) {
        int h1_item = stoi(h1_temp[i]);

        h1[i] = h1_item;
    }

    string h2_temp_temp;
    getline(cin, h2_temp_temp);

    vector<string> h2_temp = split(rtrim(h2_temp_temp));

    vector<int> h2(n2);

    for (int i = 0; i < n2; i++) {
        int h2_item = stoi(h2_temp[i]);

        h2[i] = h2_item;
    }

    string h3_temp_temp;
    getline(cin, h3_temp_temp);

    vector<string> h3_temp = split(rtrim(h3_temp_temp));

    vector<int> h3(n3);

    for (int i = 0; i < n3; i++) {
        int h3_item = stoi(h3_temp[i]);

        h3[i] = h3_item;
    }

    int result = equalStacks(h1, h2, h3);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
