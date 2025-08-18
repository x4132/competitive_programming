struct Solution;

impl Solution {
    pub fn my_atoi(s: String) -> i32 {
        let str: Vec<i32> = s.trim().chars().map(|x| x as i32).collect();
        println!("{str:?}");
        let mut out: u32 = 0;
        let mut polarity = 1;

        if str.len() == 0 {
            return 0;
        } else if str[0] == '-' as i32 {
            polarity = -1;
        } else if str[0] <= '9' as i32 && str[0] >= '0' as i32 {
            out = (str[0] - '0' as i32) as u32;
        } else if str[0] != '+' as i32 {
            return 0;
        }

        for i in 1..str.len() {
            if str[i] > '9' as i32 || str[i] < '0' as i32 {
                break;
            }

            out *= 10;
            out += (str[i] - '0' as i32) as u32;
        }

        if polarity == 1 {
            return std::cmp::min(out, std::i32::MAX as u32) as i32;
        } else if out >= 2147483648 {
            return std::i32::MIN
        } else {
            return out as i32 * -1;
        }
    }
}
