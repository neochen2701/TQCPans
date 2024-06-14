import java.util.Scanner;

class Monster {
    int value;
    Monster next;

    public Monster(int value) {
        this.value = value;
        this.next = null;
    }
}

class BattleSimulator {
    private Monster head;

    public BattleSimulator() {
        head = null;
    }

    public void createMonsters(String input) {
        String[] values = input.split(",");

        for (String value : values) {
            try {
                int monsterAttack = Integer.parseInt(value);
                addMonster(monsterAttack);
            } catch (NumberFormatException e) {
                System.out.println("input error");
            }
        }
    }

    public void addMonster(int value) {
        Monster newNode = new Monster(value);

        if (head == null) {
            head = newNode;
        } else {
            Monster current = head;
            while (current.next != null) {
                current = current.next;
            }
            current.next = newNode;
        }
    }

    public boolean simulateBattle(int playerHP) {
        Monster current = head;
        int level = 1;

        while (current != null) {
            playerHP -= current.value;

            if (playerHP <= 0) {
                System.out.println(String.format("game over! dead at level %d", level));
                return false;
            }

            level++;
            current = current.next;
        }

        System.out.println(String.format("game clear! hp left %d", playerHP));
        return true;
    }
}

public class JPA103 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();

        BattleSimulator battle = new BattleSimulator();
        battle.createMonsters(input);

        int playerHP = 100;
        battle.simulateBattle(playerHP);

        scanner.close();
    }
}
