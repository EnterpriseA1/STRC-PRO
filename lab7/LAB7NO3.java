/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab7;

/**
 *
 * @author Kkhamwiset
 */

    
class Fruit {
    
}

class Apple extends Fruit {
    void makeApple() {
        System.out.println("Making an apple");
    }
}

class Orange extends Fruit {
    void makeOrangeJuice() {
        System.out.println("Making orange juice");
    }
}

class GoldenDelicious extends Apple {
}

class Macintosh extends Apple {
}

public class  LAB7NO3 {
    public static void main(String[] args) {
        Fruit fruit = new GoldenDelicious();
        Orange orange = new Orange();

        // Answering the questions
        System.out.println("1. Is fruit instanceof Orange? " + (fruit instanceof Orange));
        System.out.println("2. Is fruit instanceof Apple? " + (fruit instanceof Apple));
        System.out.println("3. Is fruit instanceof GoldenDelicious? " + (fruit instanceof GoldenDelicious));
        System.out.println("4. Is fruit instanceof Macintosh? " + (fruit instanceof Macintosh));
        System.out.println("5. Is orange instanceof Orange? " + (orange instanceof Orange));
        System.out.println("6. Is orange instanceof Fruit? " + (orange instanceof Fruit));
        try{
            System.out.println("7. Is orange instanceof Apple? " + ((orange instanceof Apple));
        }
        catch(Exception e) {
            System.out.println("7. orange isn't instaceof Apple");
        }

        System.out.println("\n8. Trying to invoke makeApple() on fruit and orange:");
        try {
            ((Apple)fruit).makeApple();
        } catch (ClassCastException e) {
            System.out.println("Error: Cannot cast fruit to Apple - " + e.getMessage());
        }

        try {
            Orange.class.getMethod("makeApple").invoke(orange);
        } catch (Exception e) {
            System.out.println("Error: orange cannot invoke makeApple() - " + e.getMessage());
        }

        // Question 9
        System.out.println("\n9. Trying to invoke makeOrangeJuice() on orange and fruit:");
        try {
            orange.makeOrangeJuice();
        } catch (Exception e) {
            System.out.println("Error: orange cannot invoke makeOrangeJuice() - " + e.getMessage());
        }

        try {
            Fruit.class.getMethod("makeOrangeJuice").invoke(fruit);
        } catch (Exception e) {
            System.out.println("Error: fruit cannot invoke makeOrangeJuice() - " + e.getMessage());
        }
    }
}
