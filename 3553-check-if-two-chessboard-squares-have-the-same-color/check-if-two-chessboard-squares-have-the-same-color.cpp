class Solution {
public:
bool squareIsWhite(string coordinate) {
        int column = coordinate[0] - 'a' + 1; // Convert 'a' to 1, 'b' to 2, etc.
        int row = coordinate[1] - '0'; // Convert the row directly to an integer.
        return (column + row) % 2 != 0; // If sum is odd, it's white; if even, it's black.
    }
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        
        return squareIsWhite(coordinate1) == squareIsWhite(coordinate2);
    }
};