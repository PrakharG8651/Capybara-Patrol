
#  Problem: DNA Bitstring Compression 

Bruce Banner was following a project where he was examining DNA sequencing intricately. Unfortunately, the sequences were quite lengthy, even his computers were taking a significant amount of time to analyze them. In an attempt to fix this problem, he constructed a system for DNA sequence compression. In this method, we get a list of DNA match lengths M<sub>1</sub>,M<sub>2</sub>,...,M<sub>n</sub> , to compress each match length, a **continuation bit encoding** is applied to x=M<sub>i</sub>-20. Then each part is encoded according to following rules

## Encoding Rules:

To encode a single x= M<sub>i</sub> - 20
1. Convert x to binary (without leading zeros).
2. Split the binary string into groups of 3 bits from the right (least significant bits). 
 * If the leftmost group has <3 bits, pad it with leading 0s to make it 3 bits.
3. Each group becomes a **4-bit chunk**.
 * Prepend a *1* to the first(leftmost) group(it's the last order of processing).
  * Prepend a *0* to all remaining groups (processed earlier).
4. Chunks are concatenated in the order: left to right.

<pre>Input
2
23 29 </pre>

 <pre> Output
 101110010001
</pre>

### Explanation 
Step-by-step:

1. M<sub>1</sub>=23
 *  x=3 → binary: 11 → pad to 3 bits: 011

 * One group → prepend 1 → 1011
    → Encoded: 1011

2. M<sub>2</sub>=29
 * x=9 → binary: 1001

 * Groups (from right): 001, 001

 * Prepend: 0 001, 1 001
   → Encoded: 1001 0001

## Constraints-
1. 1<=n<=10<sup>5</sup>
2. 20<=M<sub>i</sub><=10<sup>9</sup>
