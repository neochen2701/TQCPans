using System;
using System.Text;

class Term
{
    public int Coefficient { get; set; }
    public int XExp { get; set; }
    public int YExp { get; set; }
    public Term Next { get; set; }

    public Term(int coefficient, int xExp, int yExp)
    {
        Coefficient = coefficient;
        XExp = xExp;
        YExp = yExp;
        Next = null;
    }
}

class Polynomial
{
    public Term Head { get; private set; }

    public void AddTerm(int coefficient, int xExp, int yExp)
    {
        if (coefficient == 0) return;

        Term newTerm = new Term(coefficient, xExp, yExp);
        if (Head == null || Head.XExp < xExp || (Head.XExp == xExp && Head.YExp < yExp))
        {
            newTerm.Next = Head;
            Head = newTerm;
            return;
        }

        Term prev = null;
        Term current = Head;
        while (current != null && (current.XExp > xExp || (current.XExp == xExp && current.YExp > yExp)))
        {
            prev = current;
            current = current.Next;
        }

        if (current != null && current.XExp == xExp && current.YExp == yExp)
        {
            current.Coefficient += coefficient;
            if (current.Coefficient == 0)
            {
                if (prev != null)
                {
                    prev.Next = current.Next;
                }
                else
                {
                    Head = current.Next;
                }
            }
        }
        else
        {
            newTerm.Next = current;
            if (prev != null)
            {
                prev.Next = newTerm;
            }
            else
            {
                Head = newTerm;
            }
        }
    }

    public override string ToString()
    {
        StringBuilder result = new StringBuilder();
        Term current = Head;
        while (current != null)
        {
            string coeffStr = current.Coefficient < 0 ? $"{current.Coefficient}" : $"+{current.Coefficient}";
            result.Append($"{coeffStr}x^{current.XExp}y^{current.YExp}");
            current = current.Next;
        }
        return result.Length > 0 ? result.ToString().TrimStart('+') : "0";
    }

    public Polynomial AddPolynomial(Polynomial other)
    {
        Polynomial result = new Polynomial();
        Term p = this.Head;
        while (p != null)
        {
            result.AddTerm(p.Coefficient, p.XExp, p.YExp);
            p = p.Next;
        }
        p = other.Head;
        while (p != null)
        {
            result.AddTerm(p.Coefficient, p.XExp, p.YExp);
            p = p.Next;
        }
        return result;
    }
}

class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        Polynomial[] polynomials = new Polynomial[n];
        for (int i = 0; i < n; i++)
        {
            polynomials[i] = new Polynomial();
            string[] terms = Console.ReadLine().Split();
            for (int j = 0; j < terms.Length; j += 3)
            {
                int coefficient = int.Parse(terms[j]);
                int xExp = int.Parse(terms[j + 1]);
                int yExp = int.Parse(terms[j + 2]);
                polynomials[i].AddTerm(coefficient, xExp, yExp);
            }
        }

        foreach (var poly in polynomials)
        {
            Console.WriteLine(poly);
        }

        Polynomial sumPoly = polynomials[0];
        for (int i = 1; i < n; i++)
        {
            sumPoly = sumPoly.AddPolynomial(polynomials[i]);
        }

        Console.WriteLine($"Sum:{sumPoly}");
    }
}
