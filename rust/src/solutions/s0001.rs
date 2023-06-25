use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map=HashMap::with_capacity(nums.len());
        for (i,num) in nums.iter().enumerate() {
            match map.get(&(target-num)) {
                Some(val)=> {
                    return vec![*val as i32, i as i32];
                },
                None=> {
                    map.insert(num, i);
                },
            }
        }
        vec![]
    }
}

#[cfg(test)]
mod tests{
    use crate::solutions::s0001::Solution;

    #[test]
    fn test_fn(){
        assert_eq!(Solution::two_sum(vec![2,7,11,15],9),vec![0,1])
    }
}
