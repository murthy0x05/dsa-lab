class Spreadsheet {
    vector<vector<int>> sheet;
public:
    Spreadsheet(int rows) {
        sheet.assign(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        int c = cell[0] - 'A';
        int r = stoi(cell.substr(1)) - 1;
        sheet[r][c] = value;
    }
    
    void resetCell(string cell) {
        int c = cell[0] - 'A';
        int r = stoi(cell.substr(1)) - 1;
        sheet[r][c] = 0;
    }
    
    int getValue(string formula) {
        int p = -1;
        for (int i = 0, n = formula.size(); i < n; i++) {
            if (formula[i] == '+') {
                p = i;
                break;
            }
        }

        string x = formula.substr(1, p);
        string y = formula.substr(p + 1);
        int X = 0, Y = 0;
        if (isalpha(x[0])) {
            X = sheet[stoi(x.substr(1)) - 1][x[0] - 'A'];
        } else {
            X = stoi(x);
        }
        if (isalpha(y[0])) {
            Y = sheet[stoi(y.substr(1)) - 1][y[0] - 'A'];
        } else {
            Y = stoi(y);
        }

        return X + Y;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */