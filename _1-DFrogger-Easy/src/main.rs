use std::{io, process};

fn main() {
    let stdin = io::stdin();
    let mut input = String::new();

    stdin.read_line(&mut input).expect("Failed to read line");

    let inputs: Vec<i16> = input.split_whitespace()
                                .map(|x| x.parse().expect(&*format!("Not an integer! {}", x)))
                                .collect();
    input.clear();

    if inputs.len() != 3 {
        eprintln!("Error in input numbers");
        process::exit(1);
    }

    let n: i16 = *inputs.get(0).unwrap();
    let s: i16 = *inputs.get(1).unwrap();
    let m: i16 = *inputs.get(2).unwrap();

    if n < 0 || s < 1 {
        eprintln!("n and s must be positive and s can't be 0");
        process::exit(1);
    }

    stdin.read_line(&mut input).expect("Failed to read line");
    let squares: Vec<i16> = input.split_whitespace()
                                .map(|x| x.parse::<i16>().expect(&*format!("Not an integer! {}", x)))
                                .collect();

    if squares.len() != (n as usize) {
        eprintln!("You must input the exact number of n");
        process::exit(1);
    }

    if squares.iter().any(|&x| x == 0 || x > 200 || x < -200) {
        eprintln!("One of inputs numbers don't fit range -200..200 or equal to zero");
        process::exit(1);
    }

    if !squares.iter().any(|&x| x == m) {
        eprintln!("One of inputs numbers have to be the magic number");
        process::exit(1);
    }

    let mut index = s;
    let mut squares_checked: Vec<i16> = Vec::new();
    loop {
        if index > n {
            println!("right");
            break;
        } else if index < 1 {
            println!("left");
            break;
        } else if squares_checked.contains(&index) {
            println!("cycle");
            break;
        }

        let val = *squares.get(index as usize - 1).unwrap();
        if val == m {
            println!("magic");
            break;
        }

        squares_checked.push(index);
        index += val;
    }
    println!("{}", squares_checked.len());
    
}