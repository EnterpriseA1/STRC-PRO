package lab5;

import java.util.ArrayList;
import java.util.Scanner;

public class LAB5NO3 {
    public static void main(String[] args) {
        SortMergeList x = null;
        SortMergeList y = null;
        for (int i = 0; i < 2; i++) {
            ArrayList<Integer> input = new ArrayList<>();
            boolean loop = true;
            Scanner in = new Scanner(System.in);
            while (loop) {
                int xi = in.nextInt();
                if (xi == 0) {
                    loop = false;
                } else {
                    input.add(xi);
                }
            }
            if (i == 0) {
                x = new SortMergeList(input);
            } else {
                y = new SortMergeList(input);
            }
        }
        
        if (x != null && y != null) {
            ArrayList<Integer> intersection = x.intersect(y.sortedList);
            System.out.println(intersection);
        } else {
            System.out.println("One of the lists is null.");
        }
    }
}

class SortMergeList {
    public ArrayList<Integer> sortedList;

    SortMergeList() {}

    SortMergeList(ArrayList<Integer> x) {
        this.sortedList = x;
    }

    public ArrayList<Integer> intersect(ArrayList<Integer> list2) {
        ArrayList<Integer> result = new ArrayList<>();
        int i = 0, j = 0;
        while (i < this.sortedList.size() && j < list2.size()) {
            if (this.sortedList.get(i).equals(list2.get(j))) {
                result.add(this.sortedList.get(i));
                i++;
                j++;
            } else if (this.sortedList.get(i) < list2.get(j)) {
                i++;
            } else {
                j++;
            }
        }
        return result;
    }
}
