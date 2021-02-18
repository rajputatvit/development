package com.test.java8;

interface Addition {

  int add(int a, int b);
}

public class MultipleArgs {

  public static void main(String[] args) {

    Addition ad = (a, b) -> {
      return a + b;
    };

    System.out.println(ad.add(10, 20));

    Addition ad1 = (int a, int b) -> {
      return a + b;
    };

    System.out.println(ad1.add(20, 30));

    Addition ad2 = (a, b) -> a + b;
    System.out.println(ad2.add(2, 3));
  }
}
