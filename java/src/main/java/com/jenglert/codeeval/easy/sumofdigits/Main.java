package com.jenglert.codeeval.easy.sumofdigits;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class Main {

    public static void main (String[] args) throws IOException {
        File file = new File(args[0]);
        BufferedReader buffer = new BufferedReader(new FileReader(file));
        String line;
        while ((line = buffer.readLine()) != null) {
            line = line.trim();
            int sum = 0;
            for (char c : line.toCharArray()) {
                int i = Integer.parseInt(c + "");
                sum += i;
            }

            System.out.println(sum);
        }
    }
}