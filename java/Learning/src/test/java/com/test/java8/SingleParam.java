package com.test.java8;

interface Sayable1 {

  String say(String name);
}

public class SingleParam {

  public static void main(String[] args) {
    Sayable1 s1 = (nm) -> {
      return "hello " + nm;
    };

    System.out.println(s1.say("Jitendra Rajput"));

    Sayable1 s2 = nm1 -> {
      return "Hello new " + nm1;
    };

    System.out.println(s2.say("Jitendra"));
  }

}
