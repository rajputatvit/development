package com.test.IBAN;

import org.apache.commons.validator.routines.IBANValidator;
import org.iban4j.Iban;
import org.junit.jupiter.api.Test;

public class IBANGeneration {

  @Test
  public void getIban() {
    for (int i = 0; i < 5; i++) {
      String iban = Iban.random().toString();
      if (validateIBAN(iban)) {
        System.out.println(iban);
      }
    }
    System.out.println("Could not generate valid IBAN");
  }

  private boolean validateIBAN(String Iban) {
    IBANValidator validator = new IBANValidator();
    return validator.isValid(Iban);
  }
}

