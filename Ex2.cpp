#include <bits/stdc++.h> 
using namespace std; 

//Khai báo hàm "precedence" để thiết lập quyền ưu tiên 
int precedence(char op){
    if(op == '+'||op == '-') 
        return 1; 
    if(op == '*'||op == '/') 
        return 2; 
    return 0; 
}

//Khai báo hàm "applyOp" để thực hiện phép toán 
int applyOp(int a, int b, char op){ 
    switch(op){ 
        case '+': 
            return a + b; 
        case '-': 
            return a - b; 
        case '*': 
            return a * b; 
        case '/': 
            return a / b; 
    } 
}

int evaluate(string s){ 
    int i; 

    stack <int> values; //khai báo stack của values
    stack <char> ops;  //Khai bảo stack của ops
      
    for(i = 0; i < s.length(); i++){ //Vòng for chạy từ 0 đến độ dài của chuỗi 

        //Nếu s[i] là khoảng trắng thì bỏ qua và tiếp tục thực hiện vòng lặp 
        if(s[i] == ' ') 
            continue; 

        // Nếu có s[i] là dấu "(" thì đẩy vô đỉnh stack của biến ops
        else if(s[i] == '('){ 
            ops.push(s[i]); 
        }

        //Hàm isdigit kiểm tra xem phần tử s[i] có phải là một số nếu số thì là true(1) còn kí tự là false(0)
        else if(isdigit(s[i])){ 
            int val = 0; //khai báo biến val = 0
            // trong khi 
            while(i < s.length() && isdigit(s[i])){   //  Trong khi i < độ dài xâu và s[i] đúng là 1 số thi ...
                val = (val*10) + (s[i]-'0');          //  Thực hiện xếp các số lần lượt đến khi gặp kí tự khác không phải số 
                i++; 
            }  
            values.push(val); // thực hiện đẩy lại giá trị sau khi đã thực hiện vô đỉnh stack của biến value
        }

        else if(s[i] == ')'){                          //Nếu phẩn tử s thứ i = ")" thì....
            while(!ops.empty() && ops.top() != '('){   
            //Kiểm tra xem trong stack ops có rỗng không: Trong khi hàm stack còn kí tự mà kí tư đầu tiên của stack ops thì "(" thì...
                int val2 = values.top(); //Khai báo biến val2 = giá trị của đỉnh stack values
                values.pop();            // đẩy giá trị đó ra ngoài stack values 
                  
                int val1 = values.top(); // Khai báo tiếp biến val1 = giá trị đỉnh stack values tiếp theo 
                values.pop();            // rồi lại tiếp tục đẩy ra ngoài 
                  
                char op = ops.top();     // Khai báo biến "op" = phần từ trên cùng của stack "ops"
                ops.pop();               // rồi sau đó thì đẩy ra ngoài 
                  
                values.push(applyOp(val1, val2, op)); 
                //sau đó ta thực hiện các phép toán với các giá trị đã lấy ra từ 2 stack trên rồi sau đó đẩy lại giá trị thu được vô stack values 
            } 
            
            // Thực hiện kiểm tra xem stack ops còn rỗng hay không: Nếu còn thì đẩy kis tự đó ra ngoài stack ops
            if(!ops.empty())    
               ops.pop(); 
        } 
          
        else{ //(Nếu không thì ...)
        //Kiêm tra: Trong khi stack ops vẫn còn kí tự và so sánh xem toán tử trên cùng stack ops có lớn hơn hoặc bằng toản tử s[i]
        //Thỏa mãn thì thực hiện vòng lặp while
            while(!ops.empty() && precedence(ops.top()) >= precedence(s[i])){ 
                int val2 = values.top(); 
                values.pop(); 
                  
                int val1 = values.top(); 
                values.pop(); 
                  
                char op = ops.top(); 
                ops.pop(); 
                //Lấy giá trị ra để thự hiện hàm applyOp() ta được giá trị mới sau đó nhét lại vào trong stack của values
                values.push(applyOp(val1, val2, op)); 
            } 
            // Còn không thỏa mãn vòng lặp while thì thực hiện đẩy kí tự s[i] vào trong stack ops
            ops.push(s[i]); 
        } 
    } 

    //Thực hiện "chốt sổ" với vòng lặp while này để có giá trị cuối cùng 
    while(!ops.empty()){ 
        int val2 = values.top(); 
        values.pop(); 
                  
        int val1 = values.top(); 
        values.pop(); 
                  
        char op = ops.top(); 
        ops.pop(); 
                  
        values.push(applyOp(val1, val2, op)); 
    } 
      
    return values.top(); // Trả về giá trị trên cùng của stack "values"
} 
    /*   
        Ví dụ với   _  (  2  +  3  )  x  2
                   _______________________
        Mảng:   i= |0| 1|2 |3 |4 |5 |6 |7 |
                   ------------------------
    
        Sau khi đến s[5]          | Sau khi đến s[7]        |   HẾT    
        values          ops       |    values       ops     |   values      ops
        |___|          |___|      |    |___|       |___|    |   |____|     |____|
        |___|          |___|     -->   |___|       |___|   -->  |____|     |____|   --> Val = 10
        |_3_|          |_+_|      |    |_2_|       |_x_|    |   |____|     |____|
        |_2_|          |_(_|      |    |_5_|       |_(_|    |   |_10_|     |_(__|

    */
int main(){ 
    //string s;
    //cin>>s;
    cout << evaluate("(2+3)*2") << endl; 
    
    return 0; 
}