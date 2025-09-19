class Spreadsheet {
    private int sheet[][];
    public Spreadsheet(int rows) {
        sheet = new int[rows][26];
        // Arrays.fill(sheet, 0);
    }
    
    public void setCell(String cell, int value) {
        int c = cell.charAt(0) - 'A';
        int r = Integer.parseInt(cell.substring(1)) - 1;
        sheet[r][c] = value;
    }
    
    public void resetCell(String cell) {
        int c = cell.charAt(0) - 'A';
        int r = Integer.parseInt(cell.substring(1)) - 1;
        sheet[r][c] = 0;
    }
    
    public int getValue(String formula) {
        int p = formula.indexOf('+');
        String x = formula.substring(1, p);
        String y = formula.substring(p + 1);

        int X = 0, Y = 0;
        if (x.charAt(0) >= 'A' && x.charAt(0) <= 'Z') {
            int c = x.charAt(0) - 'A';
            int r = Integer.parseInt(x.substring(1)) - 1;
            X = sheet[r][c];
        } else {
            X = Integer.parseInt(x);
        }
        if (y.charAt(0) >= 'A' && y.charAt(0) <= 'Z') {
            int c = y.charAt(0) - 'A';
            int r = Integer.parseInt(y.substring(1)) - 1;
            Y = sheet[r][c];
        } else {
            Y = Integer.parseInt(y);
        }

        return X + Y;
    }
}

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet obj = new Spreadsheet(rows);
 * obj.setCell(cell,value);
 * obj.resetCell(cell);
 * int param_3 = obj.getValue(formula);
 */