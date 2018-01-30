function f()
       sold::Float32 = 2.0
       snew::Float32 = 1.5
       k::Float32 = 1
       u::Float32 = .5
       while true
           if snew == 1.0 || snew == sold
               println(k)
               println(u)
               break
           else
               sold = snew
               u = u/2.0
               k = k+1
               snew = 1.0 + u
           end
       end
end

f()
