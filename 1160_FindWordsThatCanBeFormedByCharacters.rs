use std::collections::HashMap;

// struct Solution;

impl Solution {
    pub fn count_characters(words: Vec<String>, chars: String) -> i32 {
        let mut sum = 0;

        let mut lookup = HashMap::new();
        for c in chars.chars() {
            lookup.insert(c, lookup.get(&c).unwrap_or(&0) + 1);
        }

        let mut word_lookup = HashMap::new();
        let mut valid: bool;
        for words in words.iter() {
            valid = true;

            for c in words.chars() {
                word_lookup.insert(c, word_lookup.get(&c).unwrap_or(&0) + 1);

                if lookup.get(&c).unwrap_or(&0) < word_lookup.get(&c).unwrap() {
                    valid = false;
                    break;
                }
            }

            if valid {
                sum += words.len() as i32;
            }

            word_lookup.clear();
        }

        sum
    }
}
