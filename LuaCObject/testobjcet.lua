luaobjcet = luaobjcet.new(10,20)
local metable = getmetatable(luaobjcet)
if metable ~= null then
	for k,v in pairs(metable) do 
		print(k,v)
	end
end
print("luaobjcet")
