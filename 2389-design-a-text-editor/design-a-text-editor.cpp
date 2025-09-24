class TextEditor {
    struct Node {
        char data;
        Node* prev,
            * next;
        Node (char d) {
            data = d;
            prev = next = nullptr;
        }
    };
    void show(string msg) {
        cout << msg << " : ";
        for (Node* curr = head; curr; curr = curr -> next) {
            cout << curr -> data << ' ';
        }
        cout << endl;
    }

    Node* head,
        * tail;
    Node* cursor;
public:
    TextEditor() {
        head = new Node('{'); // putting dummy at starting
        tail = new Node('}'); // putting dummy at ending
        head -> next = tail;
        tail -> prev = head;
        cursor = head;
    }
    
    void addText(string text) {
        Node* ltail = cursor,
            * rhead = cursor -> next;
        
        for (const char& c: text) {
            cursor -> next = new Node(c);
            cursor -> next -> prev = cursor;
            cursor = cursor -> next;
        }

        // cout << "cursor -> " << cursor -> data << endl;
        cursor -> next = rhead;
        rhead -> prev = cursor;
        // show("addText");
    }
    
    int deleteText(int k) {
        Node* ltail = cursor,
            * rhead = cursor -> next;

        int d = 0;
        while (d < k) {
            if (cursor -> data == '{') {
                break;
            }
            Node* temp = cursor;
            cursor = cursor -> prev;
            delete temp;
            d++;
        }

        // cout << "cursor -> " << cursor -> data << endl;
        cursor -> next = rhead;
        rhead -> prev = cursor;
        // show("delete");

        return d;
    }
    
    string cursorLeft(int k) {
        string result("");

        // cout << "cursor -> " << cursor -> data << endl;
        while (k-- && cursor -> data != '{') {
            cursor = cursor -> prev;
        }

        // cout << "cursor -> " << cursor -> data << endl;

        int n = 10;
        for (Node* curr = cursor; n-- && curr -> data != '{'; curr = curr -> prev) {
            result.push_back(curr -> data);
        }

        // cout << "-- Alert!! --" << endl;
        reverse(result.begin(), result.end());
        // show(result + " l");

        return result;
    }
    
    string cursorRight(int k) {
        string result("");

        // cout << "cursor -> " << cursor -> data << endl;
        while (k-- && cursor -> next -> data != '}') {
            cursor = cursor -> next;
        }
        // cout << "cursor -> " << cursor -> data << endl;

        int n = 10;
        for (Node* curr = cursor; n-- && curr -> data != '{'; curr = curr -> prev) {
            result.push_back(curr -> data);
        }

        reverse(result.begin(), result.end());
        // show(result + " r");
        
        return result;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */