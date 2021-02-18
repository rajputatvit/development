package com.test.java8;

interface Drawable {

  void draw();
}

public class FunctionInterface {

  public static void main(String[] args) {
    int width = 10;
    Drawable d = new Drawable() {
      public void draw() {
        System.out.println(width);
      }
    };
    d.draw();
  }
}
