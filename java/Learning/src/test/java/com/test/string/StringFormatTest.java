package com.test.string;

import org.junit.jupiter.api.Test;

public class StringFormatTest {

  @Test
  public void test() {
    String test = "hello/%s/%s";
    test = String.format(test, "1", "2");
    System.out.println(test);
  }
}
