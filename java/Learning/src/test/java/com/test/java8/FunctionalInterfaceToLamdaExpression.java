package com.test.java8;

interface Drawable1 {

  void draw();
}

public class FunctionalInterfaceToLamdaExpression {

  public static void main(String[] args) {
    int width = 10;
    Drawable1 d = () -> {
      System.out.println(width);
    };
    d.draw();
  }
}
