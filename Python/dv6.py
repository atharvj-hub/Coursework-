import folium

print("--- Q12 & Q13: Combined Map Visualization ---")
coords12 = list(map(float, input("Enter Latitude and Longitude for Q12: ").split()))
name12 = input("Enter Location Name for Q12: ").strip()

n13 = int(input("Enter number of locations for Q13: "))
locations = [(name12, coords12[0], coords12[1])] # Add Q12 to the list

print("Enter Location Lat Lon per line for Q13:")
for _ in range(n13):
    entry = input().split()
    locations.append((entry[0], float(entry[1]), float(entry[2])))

# Initialize map 
m = folium.Map(location=[coords12[0], coords12[1]], zoom_start=6)

# Add all markers (Q12 + Q13)
for name, lat, lon in locations:
    folium.Marker(location=[lat, lon], popup=name).add_to(m)

m.save("merged_map.html")
print("Map successfully saved as merged_map.html. Open it in a browser to screenshot.")