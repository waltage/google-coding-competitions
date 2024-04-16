


| 1 | 5 | 2 | 3 | 4 | 0 | 6 |   |
| - | - | - | - | - | - | - | - |
| . |   |   |   |   |   |   |   |
| . | . |   |   |   |   |   |   | 
| . | . | x |   |   |   |   | 2 goes up, 5 stays as our comparator |
| 1 | 2 | 5 | 3 | 4 | 0 | 6 |   |
| . | . | . | x  |   |   |   | 3 goes up, anywhere, 5 stays as our comparator |

Linear
Iterate through the cards comparing the new string with the current last string.

If the current string is less than our comparator, charge and move it "somewhere" above.  Comparator stays the same.

If the current string is after our comparator, set it as the new comparator and continue moving.



