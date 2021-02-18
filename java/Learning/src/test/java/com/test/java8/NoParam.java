package com.test.java8;

interface Sayable {

  String say();
}

public class NoParam {

  public static void main(String[] args) {

    Sayable s = () -> {
      return "Hi I am jitendra";
    };

    final String say = s.say();
    System.out.println(say);
  }
}
