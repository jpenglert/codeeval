package com.jenglert.codeeval.hard.stringpermutations;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {

    static void doPermutation(String input, StringBuilder output, List<String> all, boolean[] used) {
        if (output.length() == input.length()) {
            all.add(output.toString());
            return;
        }

        for (int i = 0; i < input.length(); i++) {
            if (used[i]) {
                continue;
            }
            output.append(input.charAt(i));
            used[i] = true;
            doPermutation(input, output, all, used);
            used[i] = false;
            output.deleteCharAt(output.length() - 1);
        }
    }

    public static void main (String[] args) throws IOException {
        File file = new File(args[0]);
        BufferedReader buffer = new BufferedReader(new FileReader(file));
        String line;
        while ((line = buffer.readLine()) != null) {
            line = line.trim();
            List<String> all = new ArrayList<>();
            doPermutation(line, new StringBuilder(), all, new boolean[line.length()]);
            Collections.sort(all);

            StringBuilder sb = new StringBuilder();
            for (String str : all) {
                sb.append(str).append(",");
            }
            sb.deleteCharAt(sb.length() - 1);

            System.out.println(sb.toString());
        }
    }
}
