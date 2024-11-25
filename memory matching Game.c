#include <stdio.h>
        nodes[index]->symbol = temp;
    }
}

Node* getNode(int row, int col) {
    int index = row * BOARD_SIZE + col;
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current;
}

void playGame() {
    int moves = 0;
    while (1) {
        printBoard();
        char r1, c1, r2, c2;
        printf("\nEnter coordinates of two cards (e.g., A1 B2): ");
        scanf(" %c%c %c%c", &r1, &c1, &r2, &c2);

        int row1 = r1 - 'A', col1 = c1 - '1', row2 = r2 - 'A', col2 = c2 - '1';

        Node* node1 = getNode(row1, col1);
        Node* node2 = getNode(row2, col2);

        if (node1 == node2 || node1->revealed || node2->revealed) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        node1->revealed = 1;
        node2->revealed = 1;
        printBoard();

        if (node1->symbol == node2->symbol) {
            printf("Match found!\n");
        } else {
            printf("No match. Try again.\n");
            node1->revealed = 0;
            node2->revealed = 0;
        }

        moves++;

        int foundAll = 1;
        Node* current = head;
        while (current != NULL) {
            if (!current->revealed) {
                foundAll = 0;
                break;
            }
            current = current->next;
        }

        if (foundAll) {
            printf("Congratulations! You found all matches in %d moves.\n", moves);
            break;
        }
    }
}