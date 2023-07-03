<h1>Push_swap</h1>

<p>Push_swap is a data sorting tool that operates on a stack using a limited set of instructions. The goal is to sort the data with the minimum number of operations.</p>

<h2 id="about">About</h2>

<p>Push_swap is written in C and uses two stacks and a set of instructions to sort the data. It calculates and displays the smallest program that sorts the integers received as arguments.</p>

<h2 id="installation">Installation</h2>

<ol>
  <li>Clone the repository: <pre><code>git clone https://github.com/lpincoli/Push_Swap42.git</code></pre></li>
  <li>Move to the project's directory:  <pre><code>cd push_swap</code></pre></li>
  <li>Compile the project:  <pre><code>make</code></pre></li>
</ol>

<h2 id="usage">Usage</h2>

<p>To use push_swap, pass a list of integers as arguments:</p>

 <pre><code>./push_swap 5 2 3 1 4</code></pre>

<p>This will print a list of instructions that, if executed, will sort the integers. You can verify this by running the checker program:</p>

 <pre><code>./checker 5 2 3 1 4</code></pre>

<p>The checker program will read instructions from standard input. If after executing all instructions the stack is sorted and the second stack is empty, the checker will print "OK". Otherwise, it will print "KO".</p>
