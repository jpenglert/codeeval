package com.jenglert.codeeval.easy.sumofdigits;

import org.junit.Test;

import static org.junit.Assert.*;

public class MainTest {

    @Test
    public void main() throws Exception {
        Main.main(new String[] {getClass().getResource("input.txt").getPath()});
    }
}