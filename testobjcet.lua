print("luaobjcet")
local obj = Luaobject.new(10,20)
if obj ~= nil then
	 print(obj:AddSum())
 end
 local metable = getmetatable(obj)
 if metable ~= null then
	 for k,v in pairs(metable) do 
		 print(k,v)
	 end
 end
 
obj:delete()